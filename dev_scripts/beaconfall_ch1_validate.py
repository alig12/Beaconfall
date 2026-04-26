#!/usr/bin/env python3
"""
Beaconfall Chapter 1 Validator

Static structural checks for the Chapter 1 vertical slice.

This validates map integrity, chapter state wiring, and key story-flow guardrails.
It does not replace building the ROM or playing the chapter in an emulator.
"""

import json
import re
import sys
from pathlib import Path


def load_json(path):
    with open(path, "r") as f:
        return json.load(f)


def load_text(path):
    return Path(path).read_text()


def require_text(content, pattern, label):
    if re.search(pattern, content):
        return True
    print(f"❌ Missing: {label}")
    return False


def reject_text(content, pattern, label):
    if re.search(pattern, content):
        print(f"❌ Unexpected: {label}")
        return False
    return True


def script_block(content, label):
    marker = f"{label}::"
    start = content.find(marker)
    if start == -1:
        return ""
    tail = content[start + len(marker):]
    match = re.search(r"\n[A-Za-z0-9_]+::", tail)
    end = start + len(marker) + match.start() if match else len(content)
    return content[start:end]


def object_events_for(map_name):
    return load_json(f"data/maps/{map_name}/map.json").get("object_events", []) or []


def coord_events_for(map_name):
    return load_json(f"data/maps/{map_name}/map.json").get("coord_events", []) or []


def validate_map_group_membership():
    expected_maps = [
        "EmberHollowTown",
        "Route1_SaltwindPath",
        "CinderReedGrove",
        "BrassfallCity",
        "ForteHallGym",
        "EmberHollowTown_PlayersHouse_2F",
        "EmberHollowTown_PlayersHouse_1F",
        "EmberHollowTown_ProfessorLab",
    ]
    actual_maps = load_json("data/maps/map_groups.json").get("gMapGroup_BeaconfallChapter1", [])
    if actual_maps != expected_maps:
        print("❌ Map group order mismatch!")
        print(f"   Expected: {expected_maps}")
        print(f"   Got:      {actual_maps}")
        return False
    print("✓ Map group membership and order correct")
    return True


def validate_map_sections():
    regions = load_json("src/data/region_map/region_map_sections.json")
    section_ids = {s["id"] for s in regions["map_sections"]}
    required_sections = {
        "MAPSEC_EMBER_HOLLOW_TOWN",
        "MAPSEC_SALTWIND_PATH",
        "MAPSEC_CINDER_REED_GROVE",
        "MAPSEC_BRASSFALL_CITY",
    }
    if not required_sections.issubset(section_ids):
        print(f"❌ Missing region map sections: {required_sections - section_ids}")
        return False

    expected = {
        "EmberHollowTown": "MAPSEC_EMBER_HOLLOW_TOWN",
        "Route1_SaltwindPath": "MAPSEC_SALTWIND_PATH",
        "CinderReedGrove": "MAPSEC_CINDER_REED_GROVE",
        "BrassfallCity": "MAPSEC_BRASSFALL_CITY",
        "ForteHallGym": "MAPSEC_BRASSFALL_CITY",
    }
    ok = True
    for map_name, expected_section in expected.items():
        actual = load_json(f"data/maps/{map_name}/map.json").get("region_map_section", "")
        if actual != expected_section:
            print(f"❌ {map_name} uses '{actual}' instead of '{expected_section}'")
            ok = False
    if ok:
        print("✓ All maps use correct region map sections")
    return ok


def validate_connections():
    expected = {
        "MAP_EMBER_HOLLOW_TOWN": {"MAP_ROUTE1_SALTWIND_PATH"},
        "MAP_ROUTE1_SALTWIND_PATH": {"MAP_EMBER_HOLLOW_TOWN", "MAP_CINDER_REED_GROVE"},
        "MAP_CINDER_REED_GROVE": {"MAP_ROUTE1_SALTWIND_PATH", "MAP_BRASSFALL_CITY"},
        "MAP_BRASSFALL_CITY": {"MAP_CINDER_REED_GROVE"},
    }
    ok = True
    for map_name in ["EmberHollowTown", "Route1_SaltwindPath", "CinderReedGrove", "BrassfallCity"]:
        map_json = load_json(f"data/maps/{map_name}/map.json")
        actual = {c["map"] for c in (map_json.get("connections", []) or [])}
        expected_conns = expected[map_json["id"]]
        if actual != expected_conns:
            print(f"❌ {map_json['id']} connections incorrect")
            print(f"   Expected: {expected_conns}")
            print(f"   Got:      {actual}")
            ok = False
    if ok:
        print("✓ Map connections form valid chain")
    return ok


def validate_encounters():
    encounters = load_json("src/data/wild_encounters.json")
    encounter_maps = set()
    for group in encounters.get("wild_encounter_groups", []):
        if not group.get("for_maps", False):
            continue
        for enc in group.get("encounters", []):
            if "map" in enc:
                encounter_maps.add(enc["map"])

    invalid_maps = {"MAP_EMBER_HOLLOW_TOWN", "MAP_BRASSFALL_CITY", "MAP_FORTE_HALL_GYM"}
    required_maps = {"MAP_ROUTE1_SALTWIND_PATH", "MAP_CINDER_REED_GROVE"}
    if invalid_maps & encounter_maps:
        print(f"❌ Town/gym should not have encounters: {invalid_maps & encounter_maps}")
        return False
    if not required_maps.issubset(encounter_maps):
        print(f"❌ Missing encounters on: {required_maps - encounter_maps}")
        return False
    print("✓ Encounters only on Route 1 and Grove")
    return True


def validate_route1_wild_species():
    encounters = load_json("src/data/wild_encounters.json")
    allowed = {"SPECIES_PIDGEY", "SPECIES_ZIGZAGOON", "SPECIES_WURMPLE"}
    bad = []
    for group in encounters.get("wild_encounter_groups", []):
        if not group.get("for_maps", False):
            continue
        for enc in group.get("encounters", []):
            if enc.get("map") != "MAP_ROUTE1_SALTWIND_PATH":
                continue
            land = enc.get("land_mons")
            if not land:
                print("❌ MAP_ROUTE1_SALTWIND_PATH missing land_mons")
                return False
            bad += [mon.get("species", "") for mon in land.get("mons", []) if mon.get("species", "") not in allowed]
    if bad:
        print(f"❌ Saltwind Path wilds must be Pidgey/Zigzagoon/Wurmple only. Found: {sorted(set(bad))}")
        return False
    print("✓ Saltwind Path wild species match Chapter 1 spec")
    return True


def validate_no_borrowed_flags():
    borrowed_flags = {
        "FLAG_VISITED_LITTLEROOT_TOWN",
        "FLAG_WORLD_MAP_VIRIDIAN_FOREST",
        "FLAG_WORLD_MAP_VIRIDIAN_CITY",
    }
    ok = True
    for map_name in ["EmberHollowTown", "Route1_SaltwindPath", "CinderReedGrove", "BrassfallCity", "ForteHallGym"]:
        content = load_text(f"data/maps/{map_name}/scripts.inc")
        for flag in borrowed_flags:
            if flag in content:
                print(f"❌ {map_name} still uses borrowed flag: {flag}")
                ok = False
    if ok:
        print("✓ No borrowed map metadata flags found")
    return ok


def validate_expected_vars():
    content = load_text("data/scripts/chapter_1.inc")
    required = [
        "FLAG_BEACONFALL_STARTER_SELECTED",
        "VAR_RIVAL_BATTLES",
        "VAR_GYM_LIGHT_STATE",
        "FLAG_ROUTE_1_CLEARED",
        "FLAG_CINDER_REED_GROVE_CLEARED",
        "VAR_BEACONFALL_BLACKOUT_MSG",
    ]
    ok = True
    for token in required:
        if token not in content:
            print(f"❌ Chapter script missing: {token}")
            ok = False
    if ok:
        print("✓ Chapter script has expected vars and flags")
    return ok


def validate_ember_gate_flow():
    map_events = object_events_for("EmberHollowTown")
    scripts = load_text("data/maps/EmberHollowTown/scripts.inc")
    lab_scripts = load_text("data/maps/EmberHollowTown_ProfessorLab/scripts.inc")

    gate_objects = [obj for obj in map_events if obj.get("local_id") in {"LOCALID_EMBER_GATE_A", "LOCALID_EMBER_GATE_B"}]
    ok = len(gate_objects) == 2
    if not ok:
        print(f"❌ Expected 2 Ember north gate twins, found {len(gate_objects)}")
    for obj in gate_objects:
        if obj.get("flag") != "FLAG_EMBER_NORTH_GATE_TWIN_MOVED":
            print(f"❌ {obj.get('local_id')} does not use FLAG_EMBER_NORTH_GATE_TWIN_MOVED")
            ok = False

    ok &= require_text(scripts, r"FLAG_BEACONFALL_STARTER_SELECTED", "north gate checks starter-selected flag")
    ok &= require_text(scripts, r"EmberHollowTown_EventScript_OpenNorthGateCommon", "shared north gate open script")
    ok &= reject_text(scripts, r"NorthGate.*FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN", "north gate requiring tutorial rival flag")
    ok &= reject_text(lab_scripts, r"trainerbattle_single\s+TRAINER_BEACONFALL_RIVAL1", "Professor Lab Rival Battle 1")
    if ok:
        print("✓ Ember gate opens from starter state, with both twins synced")
    return ok


def validate_route1_rival_scene():
    objects = object_events_for("Route1_SaltwindPath")
    coords = coord_events_for("Route1_SaltwindPath")
    scripts = load_text("data/maps/Route1_SaltwindPath/scripts.inc")
    chapter = load_text("data/scripts/chapter_1.inc")

    mira = [obj for obj in objects if obj.get("local_id") == "LOCALID_ROUTE1_MIRA"]
    ok = True
    if len(mira) != 1:
        print(f"❌ Expected exactly one LOCALID_ROUTE1_MIRA object, found {len(mira)}")
        ok = False
    else:
        if mira[0].get("graphics_id") != "OBJ_EVENT_GFX_MAY_NORMAL":
            print("❌ Route 1 Mira should use OBJ_EVENT_GFX_MAY_NORMAL")
            ok = False
        if mira[0].get("flag") != "FLAG_ROUTE_1_CLEARED":
            print("❌ Route 1 Mira should hide with FLAG_ROUTE_1_CLEARED")
            ok = False

    rival_triggers = [c for c in coords if c.get("script") == "Route1_SaltwindPath_EventScript_RivalBattle"]
    if not rival_triggers:
        print("❌ Missing Route 1 rival coordinate triggers")
        ok = False
    for trig in rival_triggers:
        if trig.get("var") != "VAR_RIVAL_BATTLES" or trig.get("var_value") != "0":
            print("❌ Route 1 rival trigger must fire when VAR_RIVAL_BATTLES == 0")
            ok = False

    ok &= require_text(scripts, r"turnobject\s+LOCALID_ROUTE1_MIRA", "Route 1 rival scene turns visible Mira")
    ok &= require_text(scripts, r"BeaconfallChapter1_EventScript_MarkRoute1Cleared", "Route 1 rival victory marks route cleared")
    ok &= require_text(scripts, r"removeobject\s+LOCALID_ROUTE1_MIRA", "Route 1 Mira is removed after victory")
    ok &= require_text(chapter, r"BeaconfallChapter1_EventScript_MarkRoute1Cleared::[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*1", "Route 1 clear advances rival state to 1")
    if ok:
        print("✓ Route 1 uses visible Mira scene for Rival Battle 1")
    return ok


def validate_starter_poke_balls():
    chapter = load_text("data/scripts/chapter_1.inc")
    lab = load_text("data/maps/EmberHollowTown_ProfessorLab/scripts.inc")
    ok = True
    ok &= require_text(chapter, r"BeaconfallChapter1_EventScript_GiveFirstPokeBalls::", "first Poké Ball reward helper")
    ok &= require_text(chapter, r"giveitem\s+ITEM_POKE_BALL,\s*5", "Professor gives 5 Poké Balls")
    ok &= require_text(chapter, r"goto_if_set\s+FLAG_UNUSED_0x272", "one-time Poké Ball reward flag")
    ok &= require_text(lab, r"call\s+BeaconfallChapter1_EventScript_GiveFirstPokeBalls", "Professor calls catching-kit helper")
    ok &= require_text(lab, r"EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterStarter::[\s\S]*call\s+BeaconfallChapter1_EventScript_GiveFirstPokeBalls", "after-starter branch repairs missing catching kit")
    if ok:
        print("✓ Professor starter flow gives one-time 5 Poké Ball catching kit")
    return ok


def validate_forte_hall_three_rigs():
    objects = object_events_for("ForteHallGym")
    scripts = load_text("data/maps/ForteHallGym/scripts.inc")
    scripts_present = {obj.get("script") for obj in objects}
    expected_scripts = {
        "ForteHallGym_EventScript_TrainerLamp",
        "ForteHallGym_EventScript_TrainerBeam",
        "ForteHallGym_EventScript_TrainerTech",
        "ForteHallGym_EventScript_Leader",
    }
    ok = True
    missing = expected_scripts - scripts_present
    if missing:
        print(f"❌ Forte Hall missing expected object scripts: {sorted(missing)}")
        ok = False
    for flag in ["FLAG_FORTE_GYM_RIG_LEFT", "FLAG_FORTE_GYM_RIG_RIGHT", "FLAG_FORTE_GYM_RIG_CENTER"]:
        ok &= require_text(scripts, rf"setflag\s+{flag}", f"trainer/badge sets {flag}")
        ok &= require_text(scripts, rf"goto_if_unset\s+{flag},\s*ForteHallGym_EventScript_LeaderBlocked", f"Vera gates on {flag}")
    ok &= require_text(scripts, r"VAR_GYM_LIGHT_STATE is derived", "comment documents VAR_GYM_LIGHT_STATE as derived state")
    ok &= reject_text(scripts, r"goto_if_ge\s+VAR_GYM_LIGHT_STATE,\s*3,\s*ForteHallGym_EventScript_LeaderBattle", "Vera unlock based on derived VAR_GYM_LIGHT_STATE")
    if ok:
        print("✓ Forte Hall uses three rig flags as Vera's source of truth")
    return ok


def validate_progression_state_machine():
    chapter = load_text("data/scripts/chapter_1.inc")
    ember = load_text("data/maps/EmberHollowTown/scripts.inc")
    route1 = load_text("data/maps/Route1_SaltwindPath/scripts.inc")
    grove = load_text("data/maps/CinderReedGrove/scripts.inc")
    brassfall = load_text("data/maps/BrassfallCity/scripts.inc")
    gym = load_text("data/maps/ForteHallGym/scripts.inc")

    mark_route1 = script_block(chapter, "BeaconfallChapter1_EventScript_MarkRoute1Cleared")
    mark_grove = script_block(chapter, "BeaconfallChapter1_EventScript_MarkGroveCleared")
    mark_brassfall = script_block(chapter, "BeaconfallChapter1_EventScript_MarkBrassfallEntered")
    complete = script_block(chapter, "BeaconfallChapter1_EventScript_CompleteChapter")

    ok = True
    ok &= require_text(chapter, r"VAR_RIVAL_BATTLES:[\s\S]*0 = Route 1 rival pending[\s\S]*1 = Route 1 cleared; Brassfall rival pending[\s\S]*2 = Brassfall rival cleared", "documented VAR_RIVAL_BATTLES meanings")
    ok &= require_text(chapter, r"Normal marker scripts stay conservative", "conservative marker-script policy")
    ok &= require_text(chapter, r"BeaconfallChapter1_EventScript_RepairProgression::", "shared Chapter 1 progression repair helper")
    ok &= require_text(chapter, r"RepairChapterComplete::[\s\S]*setflag\s+FLAG_BRASSFALL_CITY_ENTERED[\s\S]*setflag\s+FLAG_CINDER_REED_GROVE_CLEARED[\s\S]*setflag\s+FLAG_ROUTE_1_CLEARED[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*2", "chapter-complete repair implies earlier states")
    ok &= require_text(chapter, r"RepairBrassfallEntered::[\s\S]*setflag\s+FLAG_CINDER_REED_GROVE_CLEARED[\s\S]*setflag\s+FLAG_ROUTE_1_CLEARED[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*2", "Brassfall repair implies previous states")
    ok &= require_text(chapter, r"RepairGroveCleared::[\s\S]*setflag\s+FLAG_ROUTE_1_CLEARED[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*1", "grove repair implies Route 1 clear")
    ok &= require_text(chapter, r"RepairRoute1Cleared::[\s\S]*setflag\s+FLAG_EMBER_NORTH_GATE_TWIN_MOVED[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*1", "Route 1 repair opens Ember gate")

    ok &= require_text(mark_route1, r"setflag\s+FLAG_ROUTE_1_CLEARED[\s\S]*setflag\s+FLAG_EMBER_NORTH_GATE_TWIN_MOVED[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*1", "Route 1 marker clears Route 1 and opens gate")
    ok &= require_text(mark_grove, r"setflag\s+FLAG_CINDER_REED_GROVE_CLEARED[\s\S]*return", "grove marker only sets grove-cleared flag")
    ok &= reject_text(mark_grove, r"FLAG_ROUTE_1_CLEARED|VAR_RIVAL_BATTLES", "grove marker silently repairing earlier route state")
    ok &= require_text(mark_brassfall, r"setflag\s+FLAG_BRASSFALL_CITY_ENTERED[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*2[\s\S]*return", "Brassfall marker sets city flag and rival state only")
    ok &= reject_text(mark_brassfall, r"FLAG_CINDER_REED_GROVE_CLEARED|FLAG_ROUTE_1_CLEARED", "Brassfall marker silently repairing earlier route/grove state")
    ok &= require_text(complete, r"setflag\s+FLAG_CHAPTER_1_COMPLETE[\s\S]*setflag\s+FLAG_BRASSFALL_CITY_ENTERED[\s\S]*setflag\s+FLAG_CINDER_REED_GROVE_CLEARED[\s\S]*setflag\s+FLAG_ROUTE_1_CLEARED[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*2", "chapter completion writes all implied state")

    for map_name, scripts in [
        ("EmberHollowTown", ember),
        ("Route1_SaltwindPath", route1),
        ("CinderReedGrove", grove),
        ("BrassfallCity", brassfall),
    ]:
        ok &= require_text(scripts, r"OnTransition::[\s\S]{0,160}call\s+BeaconfallChapter1_EventScript_RepairProgression", f"{map_name} transition calls shared progression repair")
    ok &= require_text(gym, r"ForteHallGym_OnLoad::[\s\S]{0,160}call\s+BeaconfallChapter1_EventScript_RepairProgression", "Forte Hall load calls shared progression repair")
    ok &= require_text(gym, r"ForteHallGym_OnTransition::[\s\S]{0,160}call\s+BeaconfallChapter1_EventScript_RepairProgression", "Forte Hall transition calls shared progression repair")
    ok &= require_text(ember, r"RepairOldTutorialGate::[\s\S]*clearflag\s+FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN[\s\S]*setvar\s+VAR_RIVAL_BATTLES,\s*0", "old tutorial-rival gate repair clears stale flag and keeps Route 1 rival pending")
    ok &= reject_text(brassfall, r"BrassfallCity_OnTransition_RivalPending", "duplicated Brassfall local rival-state repair")
    if ok:
        print("✓ Chapter 1 progression state machine is centralized while normal markers stay conservative")
    return ok


def main():
    print("\n" + "=" * 60)
    print("Beaconfall Chapter 1 Validator")
    print("=" * 60 + "\n")

    validators = [
        validate_map_group_membership,
        validate_map_sections,
        validate_connections,
        validate_encounters,
        validate_route1_wild_species,
        validate_no_borrowed_flags,
        validate_expected_vars,
        validate_ember_gate_flow,
        validate_route1_rival_scene,
        validate_starter_poke_balls,
        validate_forte_hall_three_rigs,
        validate_progression_state_machine,
    ]

    results = []
    for validator in validators:
        try:
            results.append(validator())
        except Exception as e:
            print(f"❌ Validator failed with error: {e}")
            results.append(False)
        print()

    print("=" * 60)
    print(f"Results: {sum(results)}/{len(results)} checks passed")
    print("=" * 60 + "\n")
    return 0 if all(results) else 1


if __name__ == "__main__":
    sys.exit(main())
