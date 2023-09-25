#pragma once
#include "locations.h"
#include "TossBot.h"
#include "path_manager.h"

#include <iostream>
#include <string>




namespace sc2 {

void Locations::SetLightshadeLocations(Point3D start_location, BuildOrder build_order)
{
	auto convert_location = [](Point2D point, bool swap)
	{
		if (swap)
			return Point2D(184, 164) - point;
		else
			return point;
	};

	bool swap = start_location.x == 40.5 && start_location.y == 131.5;

	this->start_location = start_location;

	nexi_locations = { convert_location(Point2D(143.5, 32.5), swap),
						convert_location(Point2D(145.5, 61.5), swap),
						convert_location(Point2D(147.3, 94.7), swap),
						convert_location(Point2D(119.5, 53.5), swap),
						convert_location(Point2D(104.5, 27.5), swap),
						convert_location(Point2D(148.5, 125.5), swap),
						convert_location(Point2D(124.5, 120.5), swap) };

	pylon_locations = { convert_location(Point2D(140, 36), swap),
						convert_location(Point2D(124, 29), swap),
						convert_location(Point2D(146.8, 99), swap),
						convert_location(Point2D(146, 91), swap),
						convert_location(Point2D(135, 36), swap),
						convert_location(Point2D(116, 50), swap),
						convert_location(Point2D(121, 57), swap),
						convert_location(Point2D(150, 26), swap),
						convert_location(Point2D(154, 64), swap),
						convert_location(Point2D(156, 97), swap),
						convert_location(Point2D(134, 24), swap),
						convert_location(Point2D(149, 45), swap),
						convert_location(Point2D(156, 92), swap),
						convert_location(Point2D(150, 70), swap),
						convert_location(Point2D(101, 27), swap),
						convert_location(Point2D(106, 31), swap),
						convert_location(Point2D(110, 21), swap),
						convert_location(Point2D(99, 20), swap),
						convert_location(Point2D(134, 26), swap) };

	pylon_locations_cannon_rush = { convert_location(Point2D(46, 90), swap),
									convert_location(Point2D(47, 92), swap),
									convert_location(Point2D(51, 100), swap),
									convert_location(Point2D(54, 94), swap) };

	first_pylon_location_zerg = convert_location(Point2D(141, 65), swap);
	first_pylon_location_protoss = convert_location(Point2D(135, 47), swap);
	first_pylon_location_terran = convert_location(Point2D(131, 45), swap);

	gateway_locations = { convert_location(Point2D(138.5, 66.5), swap),
							convert_location(Point2D(136.5, 62.5), swap),
							convert_location(Point2D(136.5, 49.5), swap),
							convert_location(Point2D(128.5, 43.5), swap),
							convert_location(Point2D(133.5, 44.5), swap),
							convert_location(Point2D(143.5, 100.5), swap),
							convert_location(Point2D(142.5, 97.5), swap),
							convert_location(Point2D(142.5, 94.5), swap),
							convert_location(Point2D(143.5, 91.5), swap),
							convert_location(Point2D(113.5, 46.5), swap),
							convert_location(Point2D(113.5, 49.5), swap),
							convert_location(Point2D(113.5, 52.5), swap),
							convert_location(Point2D(115.5, 55.5), swap),
							convert_location(Point2D(122.5, 32.5), swap),
							convert_location(Point2D(125.5, 32.5), swap),
							convert_location(Point2D(128.5, 32.5), swap),
							convert_location(Point2D(126.5, 25.5), swap),
							convert_location(Point2D(136.5, 22.5), swap),
							convert_location(Point2D(139.5, 22.5), swap),
							convert_location(Point2D(136.5, 25.5), swap),
							convert_location(Point2D(136.5, 28.5), swap),
							convert_location(Point2D(130.5, 22.5), swap),
							convert_location(Point2D(130.5, 25.5), swap),
							convert_location(Point2D(139.5, 33.5), swap),
							convert_location(Point2D(136.5, 33.5), swap),
							convert_location(Point2D(139.5, 30.5), swap),
							convert_location(Point2D(137.5, 36.5), swap),
							convert_location(Point2D(142.5, 36.5), swap),
							convert_location(Point2D(145.5, 36.5), swap),
							convert_location(Point2D(134.5, 38.5), swap),
							convert_location(Point2D(137.5, 39.5), swap),
							convert_location(Point2D(142.5, 39.5), swap), };

	assimilator_locations = { convert_location(Point2D(150.5, 35.5), swap),
								convert_location(Point2D(139.5, 25.5), swap),
								convert_location(Point2D(152.5, 58.5), swap),
								convert_location(Point2D(148.5, 54.5), swap),
								convert_location(Point2D(149.5, 87.5), swap),
								convert_location(Point2D(149.5, 101.5), swap),
								convert_location(Point2D(126.5, 56.5), swap),
								convert_location(Point2D(116.5, 46.5), swap) };


	cyber_core_locations = { convert_location(Point2D(141.7, 68.3), swap),
								convert_location(Point2D(137.5, 46.5), swap),
								convert_location(Point2D(132.5, 47.5), swap) };

	tech_locations = { convert_location(Point2D(139.5, 33.5), swap),
						convert_location(Point2D(142.5, 36.5), swap),
						convert_location(Point2D(137.5, 36.5), swap),
						convert_location(Point2D(136.5, 33.5), swap),
						convert_location(Point2D(145.5, 36.5), swap) };

	proxy_pylon_locations = { convert_location(Point2D(75.0, 136.0), swap),
								convert_location(Point2D(32.0, 66.0), swap) };

	proxy_gateway_locations = { convert_location(Point2D(75.5, 133.5), swap),
							convert_location(Point2D(34.5, 65.5), swap) };

	proxy_tech_locations = { convert_location(Point2D(77.5, 136.5), swap),
							convert_location(Point2D(78.5, 133.5), swap),
							convert_location(Point2D(32.5, 68.5), swap),
							convert_location(Point2D(35.5, 68.5), swap) };


	attack_path = { convert_location(Point2D(74, 35), swap),
					convert_location(Point2D(50, 60), swap),
					convert_location(Point2D(44, 69), swap),
					convert_location(Point2D(44, 76), swap),
					convert_location(Point2D(48, 82), swap),
					convert_location(Point2D(52, 89), swap),
					convert_location(Point2D(49, 97), swap),
					convert_location(Point2D(44, 102), swap),
					convert_location(Point2D(41, 111), swap),
					convert_location(Point2D(44, 114), swap),
					convert_location(Point2D(43, 124), swap) };

	attack_path_line = PathManager({new LineSegmentLinearY(-1 / .95, -33, 74, 34, 62.4),
									new LineSegmentCurveY(.0926, -13.056, 500.894, 62.4, 75.5),
									new LineSegmentLinearY(1, 0, -32.5, 75.5, 81.5),
									new LineSegmentCurveY(-1/14, 12.607, -504.04, 81.5, 95),
									new LineSegmentLinearY(-1, 0, 144, 95, 99), });

	high_ground_index = 8;

	attack_path_alt = { convert_location(Point2D(77, 120), swap),
						convert_location(Point2D(70, 111), swap),
						convert_location(Point2D(63, 103), swap),
						convert_location(Point2D(53, 97), swap),
						convert_location(Point2D(44, 102), swap),
						convert_location(Point2D(41, 111), swap),
						convert_location(Point2D(44, 114), swap),
						convert_location(Point2D(43, 124), swap) };

	high_ground_index_alt = 5;

	std::vector<Point2D> air_path = { convert_location(Point2D(26, 17), swap),
										convert_location(Point2D(102, 147), swap),
										convert_location(Point2D(24, 85), swap),
										convert_location(Point2D(58, 126), swap),
										convert_location(Point2D(63, 148), swap),
										convert_location(Point2D(24, 53), swap),
										convert_location(Point2D(77, 16), swap),
										convert_location(Point2D(24, 148), swap),
										convert_location(Point2D(24, 115), swap),
										convert_location(Point2D(59, 86), swap),
										convert_location(Point2D(48, 112), swap),
										convert_location(Point2D(83, 96), swap),
										convert_location(Point2D(91, 118), swap),
										convert_location(Point2D(49, 58), swap),
										convert_location(Point2D(78, 49), swap),
										convert_location(Point2D(57, 41), swap),
										convert_location(Point2D(35, 101), swap),
										convert_location(Point2D(62, 112), swap),
										convert_location(Point2D(32, 69), swap),
										convert_location(Point2D(34, 39), swap),
										convert_location(Point2D(77, 138), swap),
										convert_location(Point2D(37, 133), swap) };


	std::vector<std::vector<int>> links = {
		{5, 6, 19},
		{4, 12, 20},
		{5, 8, 9, 16, 18},
		{4, 10, 12, 17, 20, 21},
		{1, 3, 7, 20, 21},
		{0, 2, 13, 15, 18, 19}, // 5
		{0, 14, 15},
		{4, 8, 21},
		{2, 7, 10, 16, 21},
		{2, 10, 11, 13, 14, 16, 17, 18},
		{3, 8, 9, 16, 17, 21}, // 10
		{9, 12, 14, 17},
		{1, 3, 11, 17, 20},
		{5, 9, 14, 15, 18},
		{6, 9, 11, 13, 15},
		{0, 5, 6, 13, 14, 19}, // 15
		{2, 8, 9, 10},
		{3, 9, 10, 11, 12},
		{2, 5, 9, 13},
		{0, 5, 15},
		{1, 3, 4, 12}, // 20
		{3, 4, 7, 8, 10}
	};

	air_graph = new Graph(air_path, links);


	std::vector<std::vector<Point2D>> enemy_mineral_lines = { {convert_location(Point2D(40.5, 131.5), swap), convert_location(Point2D(32, 131), swap),convert_location(Point2D(42, 139), swap)},
															{convert_location(Point2D(38.5, 102.5), swap), convert_location(Point2D(38, 95), swap),convert_location(Point2D(31.5, 105.5), swap)},
															{convert_location(Point2D(36.5, 69.5), swap), convert_location(Point2D(32, 63), swap),convert_location(Point2D(32, 76), swap)},
															{convert_location(Point2D(64.5, 110.5), swap), convert_location(Point2D(57.5, 107.5), swap),convert_location(Point2D(65, 118), swap)},
															{convert_location(Point2D(35.5, 38.5), swap), convert_location(Point2D(36, 32), swap),convert_location(Point2D(28.5, 41.5), swap)},
															{convert_location(Point2D(79.5, 136.5), swap), convert_location(Point2D(71, 136), swap),convert_location(Point2D(82.5, 143.5), swap)},
															{convert_location(Point2D(59.5, 43.5), swap), convert_location(Point2D(59, 36), swap),convert_location(Point2D(52.5, 46.5), swap)} };


	warp_prism_locations = { convert_location(Point2D(50, 60), swap),
							convert_location(Point2D(76, 86), swap),
							convert_location(Point2D(62, 131), swap),
							convert_location(Point2D(76, 86), swap) };

	immortal_drop_prism_locations = { convert_location(Point2D(52, 137), swap),
										convert_location(Point2D(41, 141), swap),
										convert_location(Point2D(33, 137), swap),
										convert_location(Point2D(31, 128), swap),
										convert_location(Point2D(33, 120), swap),
										convert_location(Point2D(33, 111), swap),
										convert_location(Point2D(29, 103), swap),
										convert_location(Point2D(32, 96), swap),
										convert_location(Point2D(38, 91), swap),
										convert_location(Point2D(46, 91), swap),
										convert_location(Point2D(51, 99), swap),
										convert_location(Point2D(50, 107), swap),
										convert_location(Point2D(51, 114), swap),
										convert_location(Point2D(54, 123), swap),
										convert_location(Point2D(55, 131), swap) };

	initial_scout_pos = convert_location(Point2D(44, 114), swap);

	main_scout_path = { convert_location(Point2D(39, 121), swap),
						convert_location(Point2D(31, 126), swap),
						convert_location(Point2D(34, 141), swap),
						convert_location(Point2D(50, 141), swap),
						convert_location(Point2D(57, 134), swap),
						convert_location(Point2D(52, 122), swap), };

	natural_scout_path = { convert_location(Point2D(31, 110), swap),
							convert_location(Point2D(29, 97), swap),
							convert_location(Point2D(42, 96), swap), };

	possible_3rds = { convert_location(Point2D(36.5, 69.5), swap),
					convert_location(Point2D(64.5, 110.5), swap), };

	enemy_natural = convert_location(Point2D(38, 102), swap);


	Point2D entrance_point = convert_location(Point2D(75, 144), swap);
	Point2D exit_point = convert_location(Point2D(28, 46), swap);
	std::vector<Point2D> entrance_points = { convert_location(Point2D(48, 143), swap),
											 convert_location(Point2D(28, 111), swap),
											 convert_location(Point2D(32, 82), swap) };
	std::vector<Point2D> exit_points = { convert_location(Point2D(27, 124), swap),
										convert_location(Point2D(40, 90), swap),
										convert_location(Point2D(33, 56), swap) };;
	std::vector<Point2D> base_points = { convert_location(Point2D(40.5, 131.5), swap),
										convert_location(Point2D(38, 102), swap),
										convert_location(Point2D(36.5, 69.5), swap) };;
	std::vector<std::vector<Point2D>> exfi_paths = { {convert_location(Point2D(24, 124), swap),
														convert_location(Point2D(26, 145), swap),
														convert_location(Point2D(52, 147), swap)},
														{ convert_location(Point2D(24, 85), swap),
														convert_location(Point2D(24, 55), swap)} };

	oracle_path = OraclePath(entrance_point, exit_point, entrance_points, exit_points, base_points, exfi_paths);




	first_pylon_cannon_rush = convert_location(Point2D(137, 47), swap);

	pylon_locations_cannon_rush = { convert_location(Point2D(46, 90), swap),
									convert_location(Point2D(47, 92), swap),
									convert_location(Point2D(51, 100), swap),
									convert_location(Point2D(54, 94), swap) };

	gateway_locations_cannon_rush = { convert_location(Point2D(46.5, 94.5), swap),
									convert_location(Point2D(47.5, 84.5), swap),
									convert_location(Point2D(58.5, 89.5), swap) };

	cannon_locations_cannon_rush = { convert_location(Point2D(45, 92), swap),
									convert_location(Point2D(49, 95), swap),
									convert_location(Point2D(50, 98), swap) };

	shield_battery_locations_cannon_rush = { convert_location(Point2D(49, 93), swap),
											convert_location(Point2D(52, 98), swap),
											convert_location(Point2D(54, 96), swap),
											convert_location(Point2D(52, 96), swap),
											convert_location(Point2D(48, 90), swap),
											convert_location(Point2D(50, 90), swap) };

	robo_locations_cannon_rush = { convert_location(Point2D(46.5, 87.5), swap),
									convert_location(Point2D(0, 0), swap) };

	tech_locations_cannon_rush = { convert_location(Point2D(136.5, 49.5), swap),
									convert_location(Point2D(139.5, 46.5), swap),
									convert_location(Point2D(44.5, 84.5), swap) };

	gas_steal_locations_cannon_rush = { convert_location(Point2D(), swap),
										convert_location(Point2D(), swap),
										convert_location(Point2D(), swap),
										convert_location(Point2D(), swap) };

	third_base_pylon_gap = convert_location(Point2D(147, 97.5), swap);
	natural_door_closed = convert_location(Point2D(137.5, 64.5), swap);
	natural_door_open = convert_location(Point2D(135.5, 64.5), swap);
}

void Locations::SetTestingLocations(Point3D start_location, BuildOrder build_order)
{

	auto convert_location = [](Point2D point, bool swap)
	{
		if (swap)
			return Point2D(176, 172) - point;
		else
			return point;
	};

	bool swap = start_location.x == 142.5 && start_location.y == 140.5;

	this->start_location = start_location;

	attack_path = { convert_location(Point2D(34, 139), swap),
					convert_location(Point2D(59, 114.5), swap),
					convert_location(Point2D(85, 89), swap),
					convert_location(Point2D(112, 62.5), swap),
					convert_location(Point2D(142, 33), swap) };

	third_base_pylon_gap = convert_location(Point2D(34, 139), swap);

	nexi_locations = { convert_location(Point2D(0, 0), swap),
						convert_location(Point2D(0, 0), swap),
						convert_location(Point2D(0, 0), swap) };

	Point2D entrance_point = convert_location(Point2D(34, 139), swap);
	Point2D exit_point = convert_location(Point2D(34, 139), swap);
	std::vector<Point2D> entrance_points = { convert_location(Point2D(34, 139), swap) };
	std::vector<Point2D> exit_points = { convert_location(Point2D(34, 139), swap) };
	std::vector<Point2D> base_points = { convert_location(Point2D(34, 139), swap) };
	std::vector<std::vector<Point2D>> exfi_paths = { {convert_location(Point2D(34, 139), swap) } };

	oracle_path = OraclePath(entrance_point, exit_point, entrance_points, exit_points, base_points, exfi_paths);

}


}

