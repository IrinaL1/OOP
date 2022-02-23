#include <cstdio>
#include <string>

#include "flight_tp.h"

flight_between_two_points::flight_between_two_points(string new_start, string new_finish, int new_start_day, int new_finish_day, int new_start_time, int new_finish_time, int new_id){

	this->start = new_start;
	this->finish = new_finish;
	(this->t).start_day = new_start_day;
	(this->t).finish_day = new_finish_day;
	(this->t).start_time = new_start_time;
	(this->t).finish_time = new_finish_time;
	(this->t).flight_time = flight_time();
	this->id = new_id;

}

int flight_between_two_points::flight_time() {
	
	return ((t.finish_day - t.start_day - 1) * 60 * 24 + 60 * 24 - t.start_time + t.finish_time);
}

void flight_between_two_points::return_flight(int return_start_day, int return_start_time, flight_between_two_points * ptr) {
	
	if ((return_start_day > t.start_day) or ((return_start_day == t.start_day) && (return_start_time >= t.finish_time))) {

	int	return_finish_day = (return_start_time + t.flight_time)/(60 * 24) + return_start_day; //Если самолет прилетит уже в другой день
	int	return_finish_time = (return_start_time + t.flight_time) - (return_finish_day - return_start_day) * 60 * 24;
	flight_between_two_points RF (finish, start, return_start_day, return_finish_day, return_start_time, return_finish_time, id);
	ptr = &RF;
	}
}

bool operator<(const flight_between_two_points &f1, const flight_between_two_points &f2) {

	if ((f1.get_start_day() < f2.get_start_day()) && (f1.get_start_time() < f2.get_start_time()))
		return true;
	else
		return false;
}

bool operator==(const flight_between_two_points &f1, const flight_between_two_points &f2) {

	if ((f1.get_start_day() == f2.get_start_day()) && (f1.get_start_time() == f2.get_start_time()))
		return true;
	else
		return false;
}

string flight_between_two_points::get_start() const {
	return start;
}

string flight_between_two_points::get_finish() const {
	return finish;
}

int flight_between_two_points::get_start_day() const {
	return t.start_day;
}

int flight_between_two_points::get_finish_day() const {
	return t.finish_day;
}

int flight_between_two_points::get_start_time() const {
	return t.start_time;
}

int flight_between_two_points::get_finish_time() const {
	return t.finish_time;
}

int flight_between_two_points::get_flight_time () const {
	return t.flight_time;
}

int flight_between_two_points::get_id() const {
	return id;
}
