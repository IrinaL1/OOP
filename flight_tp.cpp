#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "flight_tp.h"

FlightBetweenTwoPoints * FlightBetweenTwoPoints::return_flight(int return_start_day, int return_start_time) const {
		
	if ((return_start_day > get_finish_day()) or ((return_start_day == get_finish_day()) && (return_start_time >= get_finish_time()))) {
	
	std::vector<struct time> ret_Time(1);
	std::vector<std::string> Points;

	Points.push_back(get_finish());
	Points.push_back(get_start());
	
	ret_Time[0].start_day = return_start_day;
	ret_Time[0].start_time = return_start_time;
	ret_Time[0].finish_day = (return_start_time + get_flight_time())/(60 * 24) + return_start_day; //Если самолет прилетит уже в другой день
	
	ret_Time[0].finish_time = (ret_Time[0].start_time + get_flight_time()) - (ret_Time[0].finish_day - ret_Time[0].start_day) * 60 * 24;
	
	return new FlightBetweenTwoPoints (Points, ret_Time, get_id());
	}
	else return NULL;
}

FlightBetweenTwoPoints* FlightBetweenTwoPoints::clone() const {
	return new FlightBetweenTwoPoints(get_points(), get_Time(), get_id());
}

bool operator<(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2) {

	return ((f1.get_start_day() < f2.get_start_day()) || ((f1.get_start_day() == f2.get_start_day()) && (f1.get_start_time() < f2.get_start_time())));

}

/*extern "C"*/ bool operator==(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2) {

	return ((f1.get_start_day() == f2.get_start_day()) && (f1.get_start_time() == f2.get_start_time()));

}

