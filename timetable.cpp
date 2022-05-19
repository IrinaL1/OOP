#include <cstdio>
#include <string>
#include <iostream>

#include "timetable.h"

Timetable::Timetable () {
	
//	first = (struct Node*)malloc(sizeof(struct Node));
	first = NULL;
}

Timetable::~Timetable () {

	if (first != NULL) {
		Node * run = first;
		Node * buff = run->next; 
		while (run != NULL) {
			buff = run->next;
			delete run->Node_ptr;
			delete run;
			run = buff;
		}
	}
}

void Timetable::push_node (Flight * Ptr) {

	Node * buff = new Node;
	buff->start_time = Ptr->get_start_time();
	buff->Node_ptr = Ptr->clone();
	buff->next = NULL;
	buff->flight_type = 1;
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
	while (run != NULL) {	
		cout << run->Node_ptr->get_start() << ' ';
			cout << Translate_day(run->Node_ptr->get_start_day()) << ' ';
			cout << Translate_time(run->Node_ptr->get_start_time()) << ' '; 
			cout << (run->Node_ptr->get_finish()) << ' ';
			cout << Translate_day(run->Node_ptr->get_finish_day()) << ' '; 
  			cout << Translate_time(run->Node_ptr->get_finish_time()) << ' ';
			cout << endl;
		run = run->next;
	}

}

int Timetable::get_flight_time (int id) {

	Node * run = first;
	int buff_time = 0;
	while (run != NULL) {
		if (run->Node_ptr && (run->Node_ptr->get_id() == id)) {
			buff_time += (run->Node_ptr->calc_flight_time());
		}
	}
	return buff_time;
}
