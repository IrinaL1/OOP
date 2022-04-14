#include <cassert>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <new>

#include "flight_tp.h"
#include "flight.h"
#include "point.h"
#include "cyclic_flight.h"
#include "timetable.h"

void test_cyclic_flight() {

	std::vector<std::string> Points_2 = {"Saint-Petesburg", "Volgograd", "Saint-Petesburg"};
	
	std::vector<struct time> Time_2(2);

	Time_2[0].start_day = 3;
	Time_2[0].start_time = 1400;
	Time_2[0].finish_day = 4;
	Time_2[0].finish_time = 120;
 
	Time_2[1].start_day = 4;
	Time_2[1].start_time = 140;
	Time_2[1].finish_day = 4;
	Time_2[1].finish_time = 400;

	CyclicFlight F2 (Points_2, Time_2, 2);

	//проверка правильности заполнения полей
	assert(F2.get_start() == "Saint-Petesburg");
	assert(F2.get_finish() == "Saint-Petesburg");
	assert(F2.get_start_day() == 3);
	assert(F2.get_finish_day() == 4);
	assert(F2.get_start_time() == 1400);
	assert(F2.get_finish_time() == 400);
	assert(F2.get_id() == 2);
	assert(F2.get_flight_time() == 420);
}

void test_flight_tp() {

	//"считываю рейсы из файла"

	std::vector<std::string> Points_1 = {"Moscow", "Astrakhan"};
	
	std::vector<struct time> Time_1(1);
	
	Time_1[0].start_day = 1;
	Time_1[0].start_time = 1260;
	Time_1[0].finish_day = 1;
	Time_1[0].finish_time = 1380;

	FlightBetweenTwoPoints F1 (Points_1, Time_1, 1);

	//проверка правильности заполнения полей
	assert(F1.get_start() == "Moscow");
	assert(F1.get_finish() == "Astrakhan");
	assert(F1.get_start_day() == 1);
	assert(F1.get_finish_day() == 1);
	assert(F1.get_start_time() == 1260);
	assert(F1.get_finish_time() == 1380);
	assert(F1.get_id() == 1);
	assert(F1.get_flight_time() == 120);
	//создаем обратный рейс и проверяем правильность полей
	FlightBetweenTwoPoints * ptr_return_flight = F1.return_flight(1, 1385);
	assert((*ptr_return_flight).get_finish() == "Moscow");
	assert((*ptr_return_flight).get_start() == "Astrakhan");
	assert((*ptr_return_flight).get_start_day() == 1);
	assert((*ptr_return_flight).get_finish_day() == 2);
	assert((*ptr_return_flight).get_start_time() == 1385);
	assert((*ptr_return_flight).get_finish_time() == 65);
	assert((*ptr_return_flight).get_id() == 1);
	assert((*ptr_return_flight).get_flight_time() == 120);
	//проверяем операторы < и ==
	assert(F1 < (*ptr_return_flight) == true);
	assert((*ptr_return_flight) < F1 == false);
	assert((*ptr_return_flight) == F1 == false);
	delete ptr_return_flight;
}

int main () {

	test_cyclic_flight();
	test_flight_tp();

	//считываю аэропорты (Point)
	std::vector<std::string> FilePoints = {"Moscow", "Tula", "Astrakhan", "Saint-Petesburg", "Volgograd"};
	std::map<std::string, Point> airpots;
	//создаю map, где ключ = название города, значение = объект Point
	for (int i = 0; i < FilePoints.size(); i++){
		airpots.emplace(FilePoints[i], Point(FilePoints[i]));
	}
	//задаю связи между городами 
	std::map <std::string, std::pair<int, int>> Moscow_bound_time;
	Moscow_bound_time.emplace("Astrakhan", make_pair(120, 135));
	Moscow_bound_time.emplace("Saint-Petesburg", make_pair(60, 90));
	Moscow_bound_time.emplace("Volgograd", make_pair(100, 120));

	std::map <std::string, std::pair<int, int>> Tula_bound_time;
	Tula_bound_time.emplace("Volgograd", make_pair(93, 104));

	std::map <std::string, std::pair<int, int>> Astrakhan_bound_time;
	Astrakhan_bound_time.emplace("Moscow", make_pair(120, 135));
	Astrakhan_bound_time.emplace("Saint-Petesburg", make_pair(150, 175));

	std::map <std::string, std::pair<int, int>> SP_bound_time;
	SP_bound_time.emplace("Moscow", make_pair(60, 80));
	SP_bound_time.emplace("Astrakhan", make_pair(150, 175));

	std::map <std::string, std::pair<int, int>> Volgograd_bound_time;
	Volgograd_bound_time.emplace("Tula", make_pair(90, 104));
	Volgograd_bound_time.emplace("Moscow", make_pair(100, 120));

	//"считываю рейсы из файла"
	std::vector<std::string> Points_1 = {"Moscow", "Volgograd"};
	
	std::vector<struct time> Time_1(1);
	
	Time_1[0].start_day = 1;
	Time_1[0].start_time = 1260;
	Time_1[0].finish_day = 1;
	Time_1[0].finish_time = 1380;

	FlightBetweenTwoPoints F1 (Points_1, Time_1, 1);

	std::vector<std::string> Points_2 = {"Volgograd", "Tula"};
	
	std::vector<struct time> Time_2(1);
	
	Time_2[0].start_day = 2;
	Time_2[0].start_time = 60;
	Time_2[0].finish_day = 2;
	Time_2[0].finish_time = 167;

	FlightBetweenTwoPoints F2 (Points_2, Time_2, 2);

	std::vector<std::string> Points_3 = {"Moscow", "Astrakhan", "Saint-Petesburg", "Moscow"};
	
	std::vector<struct time> Time_3(3);
	
	Time_3[0].start_day = 3;
	Time_3[0].start_time = 1000;
	Time_3[0].finish_day = 3;
	Time_3[0].finish_time = 1129;

	Time_3[1].start_day = 3;
	Time_3[1].start_time = 1360;
	Time_3[1].finish_day = 4;
	Time_3[1].finish_time = 70;

	Time_3[2].start_day = 4;
	Time_3[2].start_time = 120;
	Time_3[2].finish_day = 4;
	Time_3[2].finish_time = 180;

	CyclicFlight F3 (Points_3, Time_3, 3);

	Timetable T;
	T.push_node(&F2);
	T.push_node(&F3);
	T.push_node(&F1);
	T.print();

	for (int i = 0; i < FilePoints.size(); i++) {
		FilePoints[i].clear();
	}
	FilePoints.clear();
	airpots.clear();
	return 0;
}
