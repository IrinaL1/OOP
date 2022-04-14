#include <cstdio>
#include <string>

#include "flight.h"

#ifndef FLIGHT_TP_
#define FLIGHT_TP_

using namespace std;

class FlightBetweenTwoPoints: public Flight {

	public:
		FlightBetweenTwoPoints * return_flight(int return_start_day, int return_start_time) const;
		FlightBetweenTwoPoints * clone() const;
		using Flight::Flight;

};

bool operator<(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2);
bool operator==(const FlightBetweenTwoPoints &f1, const FlightBetweenTwoPoints &f2);

#endif //FLIGHT_TP_
