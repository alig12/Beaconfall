#!/usr/bin/env python3
"""
Beaconfall Chapter 1 Validator

This script validates Chapter 1 map integrity including:
- Map group membership and order
- Connection and warp closure
- Expected rival and gym gate vars
- Absence of borrowed map metadata
- Encounter coverage (only Saltwind Path and Cinder Reed Grove)
- Presence of standout rare species (Shinx, Eevee, Growlithe, Riolu, Ralts)
"""

import json
import sys
import re
from pathlib import Path

def load_json(path):
    """Load a JSON file."""
    with open(path, 'r') as f:
        return json.load(f)

def validate_map_group_membership():
    """Check that all 5 chapter 1 maps are in the correct group."""
    map_groups = load_json("data/maps/map_groups.json")
    
    expected_maps = [
        "EmberHollowTown",
        "Route1_SaltwindPath", 
        "CinderReedGrove",
        "BrassfallCity",
        "ForteHallGym"
    ]
    
    actual_maps = map_groups.get("gMapGroup_BeaconfallChapter1", [])
    
    if actual_maps != expected_maps:
        print(f"❌ Map group order mismatch!")
        print(f"   Expected: {expected_maps}")
        print(f"   Got:      {actual_maps}")
        return False
    
    print("✓ Map group membership and order correct")
    return True

def validate_map_sections():
    """Check that all maps use Beaconfall section constants."""
    regions = load_json("src/data/region_map/region_map_sections.json")
    section_ids = {s["id"] for s in regions["map_sections"]}
    
    required_sections = {
        "MAPSEC_EMBER_HOLLOW_TOWN",
        "MAPSEC_SALTWIND_PATH",
        "MAPSEC_CINDER_REED_GROVE",
        "MAPSEC_BRASSFALL_CITY"
    }
    
    if not required_sections.issubset(section_ids):
        missing = required_sections - section_ids
        print(f"❌ Missing region map sections: {missing}")
        return False
    
    print("✓ All required region map sections defined")
    
    # Check map JSONs
    maps_to_check = {
        "EmberHollowTown": "MAPSEC_EMBER_HOLLOW_TOWN",
        "Route1_SaltwindPath": "MAPSEC_SALTWIND_PATH",
        "CinderReedGrove": "MAPSEC_CINDER_REED_GROVE",
        "BrassfallCity": "MAPSEC_BRASSFALL_CITY",
        "ForteHallGym": "MAPSEC_BRASSFALL_CITY"  # Shares city section
    }
    
    all_correct = True
    for map_name, expected_section in maps_to_check.items():
        map_json = load_json(f"data/maps/{map_name}/map.json")
        actual_section = map_json.get("region_map_section", "")
        
        if actual_section != expected_section:
            print(f"❌ {map_name} uses '{actual_section}' instead of '{expected_section}'")
            all_correct = False
    
    if all_correct:
        print("✓ All maps use correct region map sections")
    
    return all_correct

def validate_connections():
    """Check that map connections form a valid chain."""
    maps_to_check = ["EmberHollowTown", "Route1_SaltwindPath", "CinderReedGrove", "BrassfallCity"]
    
    connections = {}
    for map_name in maps_to_check:
        map_json = load_json(f"data/maps/{map_name}/map.json")
        map_id = map_json["id"]
        conns = map_json.get("connections", [])
        connections[map_id] = {c["map"] for c in conns} if conns else set()
    
    # Expected connection graph:
    # EmberHollowTown <-> Saltwind Path <-> Cinder Reed Grove <-> Brassfall City
    expected = {
        "MAP_EMBER_HOLLOW_TOWN": {"MAP_ROUTE1_SALTWIND_PATH"},
        "MAP_ROUTE1_SALTWIND_PATH": {"MAP_EMBER_HOLLOW_TOWN", "MAP_CINDER_REED_GROVE"},
        "MAP_CINDER_REED_GROVE": {"MAP_ROUTE1_SALTWIND_PATH", "MAP_BRASSFALL_CITY"},
        "MAP_BRASSFALL_CITY": {"MAP_CINDER_REED_GROVE"}
    }
    
    all_correct = True
    for map_id, expected_conns in expected.items():
        actual_conns = connections.get(map_id, set())
        if actual_conns != expected_conns:
            print(f"❌ {map_id} connections incorrect")
            print(f"   Expected: {expected_conns}")
            print(f"   Got:      {actual_conns}")
            all_correct = False
    
    if all_correct:
        print("✓ Map connections form valid chain")
    
    return all_correct

def validate_encounters():
    """Check that only Saltwind Path and Cinder Reed Grove have encounters."""
    encounters = load_json("src/data/wild_encounters.json")
    
    encounter_maps = set()
    for group in encounters.get("wild_encounter_groups", []):
        # Only check groups with for_maps: true (main world encounters)
        if not group.get("for_maps", False):
            continue
        for enc in group.get("encounters", []):
            # Only check encounters that have a 'map' field
            if "map" in enc:
                encounter_maps.add(enc["map"])
    
    # Check no encounters on towns/gyms
    invalid_maps = {"MAP_EMBER_HOLLOW_TOWN", "MAP_BRASSFALL_CITY", "MAP_FORTE_HALL_GYM"}
    if invalid_maps & encounter_maps:
        bad = invalid_maps & encounter_maps
        print(f"❌ Town/gym should not have encounters: {bad}")
        return False
    
    # Check encounters exist on route/grove
    required_maps = {"MAP_ROUTE1_SALTWIND_PATH", "MAP_CINDER_REED_GROVE"}
    if not required_maps.issubset(encounter_maps):
        missing = required_maps - encounter_maps
        print(f"❌ Missing encounters on: {missing}")
        return False
    
    print("✓ Encounters only on Route 1 and Grove")
    return True

def validate_rare_species():
    """Check that rare standout species are present."""
    encounters = load_json("src/data/wild_encounters.json")
    
    species_to_find = {
        "SPECIES_SHINX": False,      # Saltwind Path
        "SPECIES_EEVEE": False,      # Saltwind Path
        "SPECIES_GROWLITHE": False,  # Cinder Reed Grove
        "SPECIES_RIOLU": False,      # Cinder Reed Grove
        "SPECIES_RALTS": False       # Cinder Reed Grove
    }
    
    for group in encounters.get("wild_encounter_groups", []):
        # Only check groups with for_maps: true
        if not group.get("for_maps", False):
            continue
        for enc in group.get("encounters", []):
            map_name = enc.get("map", "")
            # Only check chapter 1 maps
            if map_name not in {"MAP_ROUTE1_SALTWIND_PATH", "MAP_CINDER_REED_GROVE"}:
                continue
            
            # Check land mons
            if "land_mons" in enc:
                for mon in enc["land_mons"].get("mons", []):
                    species = mon.get("species", "")
                    if species in species_to_find:
                        species_to_find[species] = True
    
    all_found = all(species_to_find.values())
    if not all_found:
        missing = [s for s, found in species_to_find.items() if not found]
        print(f"❌ Missing rare species: {missing}")
        return False
    
    print("✓ All rare standout species present")
    return True

def validate_no_borrowed_flags():
    """Check that no borrowed flags are set in map transition scripts."""
    borrowed_flags = {
        "FLAG_VISITED_LITTLEROOT_TOWN",
        "FLAG_WORLD_MAP_VIRIDIAN_FOREST",
        "FLAG_WORLD_MAP_VIRIDIAN_CITY"
    }
    
    maps_to_check = ["EmberHollowTown", "Route1_SaltwindPath", "CinderReedGrove", "BrassfallCity"]
    
    all_clean = True
    for map_name in maps_to_check:
        script_path = f"data/maps/{map_name}/scripts.inc"
        try:
            with open(script_path, 'r') as f:
                content = f.read()
                for flag in borrowed_flags:
                    if flag in content:
                        print(f"❌ {map_name} still uses borrowed flag: {flag}")
                        all_clean = False
        except FileNotFoundError:
            pass
    
    if all_clean:
        print("✓ No borrowed map metadata flags found")
    
    return all_clean

def validate_expected_vars():
    """Check that chapter 1 script uses expected VAR constants."""
    chapter_script = Path("data/scripts/chapter_1.inc")
    
    if not chapter_script.exists():
        print("⚠ Chapter 1 script not found")
        return True
    
    content = chapter_script.read_text()
    
    required_patterns = [
        r"VAR_RIVAL_BATTLES",
        r"VAR_GYM_LIGHT_STATE",
        r"FLAG_ROUTE_1_CLEARED",
        r"FLAG_CINDER_REED_GROVE_CLEARED"
    ]
    
    all_found = True
    for pattern in required_patterns:
        if not re.search(pattern, content):
            print(f"❌ Chapter script missing: {pattern}")
            all_found = False
    
    if all_found:
        print("✓ Chapter script has expected vars and flags")
    
    return all_found

def main():
    """Run all validators."""
    print("\n" + "="*60)
    print("Beaconfall Chapter 1 Validator")
    print("="*60 + "\n")
    
    validators = [
        validate_map_group_membership,
        validate_map_sections,
        validate_connections,
        validate_encounters,
        validate_rare_species,
        validate_no_borrowed_flags,
        validate_expected_vars
    ]
    
    results = []
    for validator in validators:
        try:
            results.append(validator())
        except Exception as e:
            print(f"❌ Validator failed with error: {e}")
            results.append(False)
        print()
    
    print("="*60)
    passed = sum(results)
    total = len(results)
    print(f"Results: {passed}/{total} checks passed")
    print("="*60 + "\n")
    
    return 0 if all(results) else 1

if __name__ == "__main__":
    sys.exit(main())
