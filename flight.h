#include <cstdio>
#include <string>
#include <vector>

#ifndef FLIGHT_H_
#define FLIGHT_H_

struct time {

	int start_day;
	int finish_day;
	int start_time;
	int finish_time;

};

class Flight {

	std::vector<struct time> Time;
	std::vector<std::string> Points;
	int flight_time;
	int id;

	public: 
	std::string get_start() const;
	std::string get_finish() const;
	int get_start_day() const;
	int get_finish_day() const;
	int get_start_time() const;
	int get_finish_time() const;
	int get_flight_time() const;
	int get_id() const;
	std::vector<std::string> get_points() const;
	std::vector<struct time> get_Time() const;
	Flight(std::vector<std::string> new_Points, std::vector<struct time> new_Time, int id);
	~Flight();
	int calc_flight_time(); 
};

#endif //FLIGHT_H_
