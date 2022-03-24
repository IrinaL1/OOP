#include <cstdio>
#include <string>

#include "flight_tp.h"

FlightBetweenTwoPoints * FlightBetweenTwoPoints::return_flight(int return_start_day, int return_start_time) const {
	
	if ((return_start_day > get_finish_day()) or ((return_start_day == get_finish_day()) && (return_start_time >= get_finish_time()))) {

	struct time * ret_Time = new struct time;
	string * Points = new string;

	*Points = get_finish();
	*(Points + 1) = get_start();
	ret_Time->start_day = return_start_day;
	ret_Time->start_time = return_start_time;

	ret_Time->finish_day = (return_start_time + get_flight_time())/(60 * 24) + return_start_day; //Если самолет прилетит уже в другой день
	ret_Time->finish_time = (ret_Time->start_time + get_flight_time()) - (ret_Time->finish_day - ret_Time->start_day) * 60 * 24;

	
	return new FlightBetweenTwoPoints (2, Points, ret_Time);
	}
	else return NULL;
	
}

bool operator<(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2) {

	return ((f1.get_start_day() < f2.get_start_day()) && (f1.get_start_time() < f2.get_start_time()));

}

bool operator==(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2) {

	return ((f1.get_start_day() == f2.get_start_day()) && (f1.get_start_time() == f2.get_start_time()));

}

