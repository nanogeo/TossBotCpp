#pragma once
#include "locations.h"
#include "TossBot.h"
#include "path_manager.h"
#include "definitions.h"

#include <iostream>
#include <string>

#define P(x, y) convert_location(Point2D(x, y), swap)


namespace sc2 {

	void Locations::SetOceanbornLocations(Point3D start_location, BuildOrder build_order)
	{
		Point2D center_point = Point2D(100, 94);

		auto convert_location = [](Point2D point, bool swap)
		{
			if (swap)
				return Point2D(200, 188) - point;
			else
				return point;
		};

		bool swap = start_location.x == 43.5 && start_location.y == 141.5;

		this->start_location = start_location;

		nexi_locations = { P(156.5, 46.5),
							P(154.5, 75.5),
							P(131.5, 54.5),
							P(141.5, 95.5),
							P(107.5, 46.5),
							P(154.5, 123.5),
							P(76.5, 39.5) };

		pylon_locations = { P(155, 50),
							P(155, 52),
							P(127, 53),
							P(132, 58),
							P(142, 100),
							P(138, 94),
							P(104, 44),
							P(78, 43),
							P(151, 122),
							P(138, 41),
							P(155, 39),
							P(165, 47) };

		first_pylon_location_zerg = P(148, 73);
		first_pylon_location_protoss = P(161, 60);
		first_pylon_location_terran = P(145, 53);

		gateway_locations = { P(159.5, 63.5),
								P(165.5, 62.5),
								P(145.5, 55.5),
								P(145.5, 68.5),
								P(145.5, 72.5),
								P(122.5, 50.5),
								P(124.5, 53.5),
								P(127.5, 55.5),
								P(129.5, 58.5),
								P(143.5, 105.5),
								P(141.5, 102.5),
								P(139.5, 99.5),
								P(137.5, 96.5),
								P(138.5, 43.5),
								P(141.5, 43.5),
								P(131.5, 38.5),
								P(158.5, 36.5),
								P(155.5, 36.5),
								P(152.5, 36.5),
								P(167.5, 45.5),
								P(167.5, 48.5) };

		assimilator_locations = {  };


		cyber_core_locations = { P(158.5, 60.5),
								P(142.5, 52.5),
								P(144.5, 75.5) };

		tech_locations = { P(152.5, 45.5),
							P(152.5, 48.5),
							P(152.5, 51.5),
							P(152.5, 54.5),
							P(149.5, 48.5),
							P(149.5, 51.5),
							P(157.5, 50.5),
							P(157.5, 53.5) };

		proxy_pylon_locations = {  };

		proxy_gateway_locations = {  };

		proxy_tech_locations = {  };


		attack_path = { P(95, 110),
						P(83, 122),
						P(80, 125),
						P(76, 127.5),
						P(70, 127.5),
						P(66, 125),
						P(60, 119),
						P(56, 116),
						P(51, 117.5),
						P(48, 120),
						P(42, 126) };

		attack_path_line = PathManager({new LineSegmentLinearX(-1, 205, 80, 95, swap, center_point, true),
										new LineSegmentCurveX(-3/49, 438/49, 9715/49, 66, 80, swap, center_point, true),
										new LineSegmentLinearX(1, 59, 58, 66, swap, center_point, true),
										new LineSegmentCurveX(.085, -93415, 372.858, 49, 58, swap, center_point, true),
										new LineSegmentLinearX(-1, 168.2, 42, 49, swap, center_point, true) }, false, swap);

		high_ground_index = 10;

		attack_path_alt = { P(78, 52),
							P(63, 63),
							P(70, 78),
							P(65, 90),
							P(72, 108),
							P(60, 119),
							P(56, 116),
							P(51, 117.5),
							P(48, 120),
							P(42, 126) };

		high_ground_index_alt = 9;

		initial_scout_pos = P(43.5, 124.5);

		main_scout_path = { P(34, 138),
							P(41, 150),
							P(57, 145),
							P(52, 133) };

		natural_scout_path = { P(37, 117),
								P(42, 103),
								P(51, 108) };

		possible_3rds = { P(68.5, 133.5), P(58.5, 92.5)};

		enemy_natural = P(45.5, 112.5);


		/*Point2D entrance_point = P(, );
		Point2D exit_point = P(, );
		std::vector<Point2D> entrance_points = { P(, ),
												 P(, ),
												 P(, ) };
		std::vector<Point2D> exit_points = { P(, ),
											P(, ),
											P(, ) };;
		std::vector<Point2D> base_points = { P(, ),
											P(, ),
											P(, ) };;
		std::vector<std::vector<Point2D>> exfi_paths = { {P(, ),
															P(, ),
															P(, )},
															{ P(, ),
															P(, )} };

		oracle_path = OraclePath(entrance_point, exit_point, entrance_points, exit_points, base_points, exfi_paths);*/



		third_base_pylon_gap = P(128.5, 53);
		natural_door_closed = P(145, 70.5);
		natural_door_open = P(142, 70.5);


		adept_harrass_protoss_consolidation = { P(68, 125), P(70, 100) };

		main_early_dead_space = P(140, 41);
		natural_front = { P(142.5, 74.5),
						P(145.5, 68) };


		adept_scout_shade = P(61, 115);
		adept_scout_runaway = P(71, 106);
		adept_scout_ramptop = P(43.5, 124.5);
		adept_scout_nat_path = { P(45, 102),
								P(37, 115) };
		adept_scout_base_spots = { P(34, 143),
									P(46, 150),
									P(55, 146),
									P(56, 136) };

		blink_presure_consolidation = P(79, 123);
		blink_pressure_prism_consolidation = P(84, 118);
		blink_pressure_blink_up = P(64, 137);
		blink_pressure_blink_down = P(60, 142);

		blink_nat_attacK_path_line = PathManager({ new LineSegmentLinearX(.59, 84.5, 45, 63, swap, center_point, true),
													new LineSegmentCurveX(-.04, 5.76, -82.46, 63, 79, swap, center_point, true) }, true, swap);

		blink_main_attack_path_lines = { PathManager({ new LineSegmentLinearX(.75, 97, 45, 60, swap, center_point, true) }, true, swap),
										PathManager({ new LineSegmentCurveY(-.14, 39.76, -2762.96, 142, 152, swap, center_point, true) }, false, swap) };
	}
	
}

