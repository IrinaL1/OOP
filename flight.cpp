#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "flight.h"

int Flight::calc_flight_time(){

	int flight_time = 0;
	for (int i = 0; i < Points.size() - 1; i++) {

		flight_time += ((Time + i)->finish_day - (Time + i)->start_day - 1) * 60 * 24 + (60 * 24 - (Time + i)->start_time) + (Time + i)->finish_time;
	}
	return flight_time;
}

Flight::Flight(std::vector<std::string> new_Points, struct time * new_Time, int new_id){

	Points = new_Points;
	Time = new_Time;
	flight_time = calc_flight_time();
	std::cout << "Flight\n";
	id = new_id;
}

Flight::~Flight () {
	
	std::cout << "Before flight destr" << std::endl;
	for (int i = 0; i < Points.size(); i++) {
		Points[i].clear();
	}
	Points.clear();
	delete [] Time;
	std::cout << "After flight destr" << std::endl;
}

std::string Flight::get_start() const{
	return Points[0];
}

std::string Flight::get_finish() const{
	return Points[Points.size()-1];
}

int Flight::get_start_day() const{
	std::cout << Time->start_day << std::endl; 
	return Time->start_day;
}

int Flight::get_finish_day() const{
	return (Time + Points.size() - 2)->finish_day;
}

int Flight::get_start_time() const{
	std::cout << " in get_start_time " << std::endl;
	return Time->start_time;
}

int Flight::get_finish_time() const{
	return (Time + Points.size() - 2)->finish_time;
}

int Flight::get_flight_time() const{
	return flight_time;
}

int Flight::get_id() const{
	return id;
}
