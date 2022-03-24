#include <cstdio>
#include <string>

#ifndef FLIGHT_H_
#define FLIGHT_H_

using namespace std;

struct time {

	int start_day;
	int finish_day;
	int start_time;
	int finish_time;

};

class Flight {

	string * Points;
	struct time * Time;
//	static int id;
	int flight_time;
	int Num_P; //количество пунктов в рейсе, должно быть не меньше 2
	int id;

	public: 
	string get_start() const;
	string get_finish() const;
	int get_start_day() const;
	int get_finish_day() const;
	int get_start_time() const;
	int get_finish_time() const;
	int get_flight_time() const;
	int get_id() const;
	Flight(int Num_P, string * new_Points, struct time * new_Time);
	void calc_flight_time();//private?
	//обртный только в дочернем и перегрузка там же(сделать структуру время public? или использовать геттеры). Для цикл сделать прикольный геттер. 
};

#endif //FLIGHT_H_
