#include <cstdio>
#include <string>

#ifndef FLIGHT_TP_
#define FLIGHT_TP_

#include "flight.h"

using namespace std;

class FlightBetweenTwoPoints: public Flight {

	public:
		FlightBetweenTwoPoints * return_flight(int return_start_day, int return_start_time) const;
		using Flight::Flight;
//		FlightBetweenTwoPoints(string * new_Points, struct time * new_Time, int Num_P = 2): 
//			Flight(2, new_Points, new_Time) {}

};

bool operator<(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2);
bool operator==(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2);

#endif 
