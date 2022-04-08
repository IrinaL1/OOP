#include <cstdio>
#include <string>
#include <iostream>

#include "timetable.h"

Timetable::Timetable () {
	
//	first = (struct Node*)malloc(sizeof(struct Node));
	first = NULL;
}

Timetable::~Timetable () {

	Node * run = first;
	Node * buff = run->next; //(struct Node*)malloc(sizeof(struct Node));
	while (run != NULL) {
	cout << "Timetable destr 1" << std::endl;

		buff = run->next;
	cout << "Timetable destr 1.5" << std::endl;
		if ((*run).get_flight_type() == 1) {
			delete run->Node_ptr_fbtp;
			cout << "In if Timetable" << std::endl;
		}
		else { 
			delete run->Node_ptr_cf;
			cout << "In else Timetable" << std::endl;
		}
	cout << "Timetable destr 2" << std::endl;
		delete run;
		run = buff;
	}
	cout << "Timetable destr 3" << std::endl;
}

void Timetable::push_node (FlightBetweenTwoPoints * Ptr_fbtp) {

	Node * buff = (struct Node*)malloc(sizeof(struct Node));
	buff->start_time = (*Ptr_fbtp).get_start_time();
	std::cout << " 1 " << std::endl;
	buff->Node_ptr_fbtp = Ptr_fbtp;
	std::cout << "2" << std::endl;
	buff->next = NULL;
	buff->flight_type = 1;
	Node * run = first;

	if (first == NULL) {
		std::cout << "3" << std::endl;
		first = buff;		
	}
	else {
		while (run->next != NULL) {
			std::cout << "4" << std::endl;
			if (run->next->start_time > buff->start_time) {
				break;
			}
			run = run->next;
			std::cout << "5" << std::endl;
		}
	//	buff->next = (struct Node*)malloc(sizeof(struct Node));
		std::cout << "6" << std::endl;
		buff->next = run->next;
		std::cout << "7" << std::endl;
		run->next = buff;
	}
}

void Timetable::push_node (CyclicFlight * Ptr_cf) {

	Node * buff = (struct Node*)malloc(sizeof(struct Node));
	buff->start_time = (*Ptr_cf).get_start_time();
	(buff->Node_ptr_cf) = Ptr_cf;
	buff->next = NULL;
	buff->flight_type = 2;
	Node * run = first;

	if (first == NULL) {
		first = buff;		
	}
	else {
		while (run->next != NULL) {
			if (run->next->start_time > buff->start_time) {
				break;
			}
			run = run->next;
		}
	//	buff->next = (struct Node*)malloc(sizeof(struct Node));
		buff->next = run->next;
		std::cout << "8" << std::endl;
		run->next = buff;
	}
}

string Translate_day(int day) {

	switch (day) 
	{
		case 0:
			return "Monday";
		case 1:
			return "Tuesday";
		case 2:
			return "Wednesday";
		case 3:
			return "Thursday";
		case 4:
			return "Friday";
		case 5:
			return "Saturday";
		case 6:
			return "Sunday";
	}

}

string Translate_time(int time) {

	//char * hour = itoa(time / 60);
	//char * minute = itoa(time % 60);
	//char * translate_time = char[strlen(hour) + strlen(minute) + 2];
	//strcat(translate_time, hour);
	//strcat(translate_time; ':');
	//strcat(translate_time, minute);
	string translate_time = to_string(time / 60) + ':' + to_string(time % 60);
	return translate_time;
}

void Timetable::print () {
	
//	Node * run = (struct Node*)malloc(sizeof(struct Node));
	Node * run = first;
	std::cout << "In print 1" << std::endl;
	while (run != NULL) {
		std::cout <<"type " <<(*run).get_flight_type() << std::endl;
		if ((*run).get_flight_type() == 2) {	
			cout << "In if" << std::endl;
			cout << (*(run->Node_ptr_cf)).get_start() << ' ';
			cout << Translate_day((*(run->Node_ptr_cf)).get_start_day()) << ' ';
			cout << Translate_time((*(run->Node_ptr_cf)).get_start_time()) << ' '; 
			cout << (*(run->Node_ptr_cf)).get_finish() << ' ';
			cout << Translate_day((*(run->Node_ptr_cf)).get_finish_day()) << ' '; 
  			cout << Translate_time((*(run->Node_ptr_cf)).get_finish_time()) << ' ';
			cout << endl;
		}
		else {
			cout << "In else" << std::endl;
			cout << (*(run->Node_ptr_fbtp)).get_start() << ' ';
			cout << Translate_day((*(run->Node_ptr_fbtp)).get_start_day()) << ' ';
			cout << Translate_time((*(run->Node_ptr_fbtp)).get_start_time()) << ' '; 
			cout << (*(run->Node_ptr_fbtp)).get_finish() << ' ';
			cout << Translate_day((*(run->Node_ptr_fbtp)).get_finish_day()) << ' '; 
  			cout << Translate_time((*(run->Node_ptr_fbtp)).get_finish_time()) << ' ';
			cout << endl;
		}
		run = run->next;
	}

}

int Timetable::get_flight_time (int id) {

	Node * run = first;
	int buff_time = 0;
	while (run != NULL) {
		if (run->Node_ptr_cf && ((*(run->Node_ptr_cf)).get_id() == id)) {
			buff_time += (*(run->Node_ptr_cf)).calc_flight_time();
		}
		else if (run->Node_ptr_fbtp && ((*(run->Node_ptr_cf)).get_id() == id)) {
			buff_time += (*(run->Node_ptr_fbtp)).calc_flight_time();
		}
	}
	return buff_time;
}

