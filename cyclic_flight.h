#include <cstdio>
#include <string>
#include <vector>

#include "flight.h"
#ifndef CYCLIC_FLIGHT_H
#define CYCLIC_FLIGHT_H

class CyclicFlight: public Flight {

	public:
		CyclicFlight * clone() const;
		using Flight::Flight;
};

#endif //CYCLIC_FLIGHT_H
