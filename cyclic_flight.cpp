#include <cstdio>

#include "cyclic_flight.h"

CyclicFlight * CyclicFlight::clone() const {
	return new CyclicFlight(get_points(), get_Time(), get_id());
}

