#!/usr/bin/env python3
"""Final verification that all changes are in place"""
import json
import sys

print("Chapter 1 Pass Implementation Verification\n")

# Check 1: Region map sections
try:
    with open('src/data/region_map/region_map_sections.json') as f:
        regions = json.load(f)
        section_ids = {s['id'] for s in regions['map_sections']}
        required = {'MAPSEC_EMBER_HOLLOW_TOWN', 'MAPSEC_SALTWIND_PATH', 'MAPSEC_CINDER_REED_GROVE', 'MAPSEC_BRASSFALL_CITY'}
        assert required.issubset(section_ids), 'Missing region sections'
        print('✓ Region map sections: 4/4 present')
except Exception as e:
    print(f'✗ Region sections check failed: {e}')
    sys.exit(1)

# Check 2: Map JSONs use correct sections
try:
    maps = {
        'data/maps/EmberHollowTown/map.json': 'MAPSEC_EMBER_HOLLOW_TOWN',
        'data/maps/Route1_SaltwindPath/map.json': 'MAPSEC_SALTWIND_PATH',
        'data/maps/CinderReedGrove/map.json': 'MAPSEC_CINDER_REED_GROVE',
        'data/maps/BrassfallCity/map.json': 'MAPSEC_BRASSFALL_CITY',
    }
    for path, expected_section in maps.items():
        with open(path) as f:
            data = json.load(f)
            actual = data.get('region_map_section')
            assert actual == expected_section, f'{path}: expected {expected_section}, got {actual}'
    print('✓ Map JSONs: All 4 use correct sections')
except Exception as e:
    print(f'✗ Map JSON check failed: {e}')
    sys.exit(1)

# Check 3: Encounters in group 0
try:
    with open('src/data/wild_encounters.json') as f:
        encounters = json.load(f)
        group0_maps = {e.get('map') for e in encounters['wild_encounter_groups'][0]['encounters'] if 'map' in e}
        assert 'MAP_ROUTE1_SALTWIND_PATH' in group0_maps
        assert 'MAP_CINDER_REED_GROVE' in group0_maps
        print('✓ Encounters: Both maps in group 0')
except Exception as e:
    print(f'✗ Encounter check failed: {e}')
    sys.exit(1)

# Check 4: Borrowed flags removed
try:
    for map_name in ['EmberHollowTown', 'CinderReedGrove', 'BrassfallCity']:
        with open(f'data/maps/{map_name}/scripts.inc') as f:
            content = f.read()
            assert 'FLAG_VISITED_LITTLEROOT_TOWN' not in content
            assert 'FLAG_WORLD_MAP_VIRIDIAN' not in content
    print('✓ Borrowed flags: All removed')
except Exception as e:
    print(f'✗ Flag check failed: {e}')
    sys.exit(1)

# Check 5: Files exist
try:
    import os
    assert os.path.exists('dev_scripts/beaconfall_ch1_validate.py')
    assert os.path.exists('docs/beaconfall_chapter1_validator.md')
    print('✓ Files: Validator and documentation present')
except Exception as e:
    print(f'✗ File check failed: {e}')
    sys.exit(1)

print("\n✓ All implementation checks passed!")
