#include <cstdio>
#include <string>

#include "flight_tp.h"
#include "cyclic_flight.h"

#ifndef TIMETABLE_H_
#define TIMETABLE_H_

struct Node {

	int start_time;
	FlightBetweenTwoPoints * Node_ptr_fbtp = NULL;
	CyclicFlight * Node_ptr_cf = NULL;
	Node * next;
	int flight_type; //1, если между 2 пунктами; 2, если циклический	
	
	public:
	int get_flight_type() { return flight_type; };
};

class Timetable {

	Node * first;

	public:
	Timetable();
	void push_node (FlightBetweenTwoPoints * Ptr_fbtp);
	void push_node (CyclicFlight * Ptr_cf);
	void print ();
	int get_flight_type();
	int get_flight_time(int id);
	~Timetable();
};

#endif //TIMETABLE_H_
