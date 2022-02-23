#include <cstdio>
#include <string>
#ifndef FLIGHT_TP_
#define FLIGHT_TP_

using namespace std;

struct time {
	int start_day;
	int finish_day;
	int start_time;
	int finish_time;
	int flight_time;
};

class flight_between_two_points {

	string start;
	string finish;
	struct time t;
	int id;

	public:
		int flight_time(); //расчет времени полета для конкретного рейса
		string get_start() const;
		string get_finish() const;
		int get_start_day() const;
		int get_finish_day() const;
		int get_start_time() const;
		int get_finish_time() const;
		int get_flight_time() const;
		int get_id() const;		
		void return_flight(int return_start_day, int return_start_time, flight_between_two_points * ptr);
		flight_between_two_points(string new_start, string new_finish, int new_start_day, int new_finish_day, int new_start_time, int new_finish_time, int new_id);

};

#endif 
