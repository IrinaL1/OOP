#include <cstdio>
#include <string>

#include "flight.h"

Flight::Flight(int Num_P, std::string * new_Points, struct time * new_Time){

	this -> Num_P = Num_P;
	Points = new_Points;
	Time = new_Time;
	calc_flight_time();

}

void Flight::calc_flight_time(){

	for (int i = 0; i < Num_P - 1; i++) {

		this->flight_time += ((Time + i)->finish_day - (Time + i)->start_day - 1) * 60 * 24 + (60 * 24 - (Time + i)->start_time) + (Time + i)->finish_time;
	}
}

string Flight::get_start() const{
	return *Points;
}

string Flight::get_finish() const{
	return *(Points + Num_P - 1);
}

int Flight::get_start_day() const{
	return Time -> start_day;
}

int Flight::get_finish_day() const{
	return (Time + Num_P - 2) -> finish_day;
}

int Flight::get_start_time() const{
	return Time -> start_time;
}

int Flight::get_finish_time() const{
	return (Time + Num_P - 2) -> finish_time;
}

int Flight::get_flight_time() const{
	return flight_time;
}

int Flight::get_id() const{
	return id;
}
