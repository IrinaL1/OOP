#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "timetable.h"
#include "point.h"
#include "flight_tp.h"
#include "flight.h"
#include "cyclic_flight.h"


extern "C" Timetable * create_timetable(char * filename) {
		cout << "Start" << '\n';
		ifstream file_ptr(filename);
		//file_ptr.open(filename);
		if (!file_ptr) cout << "No such file" << '\n';
		cout << "Start" << '\n';
		Timetable * T = new Timetable;
		//считываю названия эропортов
		std::string buf;
		std::string buf_1;
		std::vector<std::string> FilePoints;
		cout << "Start" << '\n';
		if(file_ptr.is_open()) cout << "Open" << '\n';
		int i = 0;
		bool b;
		while (std::getline(file_ptr, buf)) {
			if(buf == ";") break;
			FilePoints.push_back(buf);
			cout << "in while" << '\n';
			cout << i << '\n';
			cout << buf;
			cout << b << '\n';
			i++;
		}
		if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n'; //считываю разделитель

		//создаю аэропорты-объекты
		std::map<std::string, Point> airports;
		std::string name_1;	//аэропорт, для которого задаю связи
		std::string name_2; //связанные аэропорты
		int min_time;
		int max_time;
		std::map <std::string, std::pair<int, int>> bound_time;

		while(file_ptr.peek() != '.') {
			if(!std::getline(file_ptr, name_1)) cout << name_1 << '\n';
			while(file_ptr.peek() != ';' && std::getline(file_ptr, name_2)) {
				if(!std::getline(file_ptr, buf)) 
					cout << "Error reading min_time airports" << '\n';
				else{
					min_time = stoi(buf);
					if(min_time <= 20)
						cout << "Incorrect min_time" << '\n';
				}
				if(!std::getline(file_ptr, buf)) 
					cout << "Error reading max_time airports" << '\n';
				else{
					max_time = stoi(buf);
					if(max_time <= 20 || max_time < min_time)
						cout << "Incorrect max_time" << '\n';
				}
				bound_time.emplace(name_2, make_pair(min_time, max_time));			
			}
				airports.emplace(name_1, Point(name_1, bound_time));
		}
		
		if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n'; //считываю разделитель
		cout << "After airports" << '\n';
		//задаю рейсы
		//name_1 - город отправления
		//name_2 - буфер, в который считываю следующие города в рейсе
		std::vector<std::string> FlightPoints;
		std::vector<struct time> FlightTime;
		struct time BufTime;
		int id;

		while(!file_ptr.eof()){
			if(!std::getline(file_ptr, name_1)) cout << "Error reading or End of file" << '\n';
			FlightPoints.push_back(name_1);
			//считываю города в рейсе
			while(file_ptr.peek() != ';' && std::getline(file_ptr, name_2))
				FlightPoints.push_back(name_2);
			if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n'; //считываю разделитель
			if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
			else id = stoi(buf);

			while(file_ptr.peek() != ';' && std::getline(file_ptr, buf)){
				BufTime.start_day = stoi(buf);
				if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
				BufTime.finish_day = stoi(buf);
				if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
                BufTime.start_time = stoi(buf);
				if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
                BufTime.finish_time = stoi(buf);
				FlightTime.push_back(BufTime);
     		}

			if(FlightPoints.size() == 2){ 
				FlightBetweenTwoPoints F (FlightPoints, FlightTime, id);
				T->push_node(&F);
			}
			else {
				CyclicFlight F (FlightPoints, FlightTime, id);
				T->push_node(&F);
			}
			if(!std::getline(file_ptr, buf)) cout << "Error reading or End of file" << '\n'; //считываю разделитель
		}
		
		file_ptr.close();
		return T;
	}
		
extern "C" int l_get_flight_time(Flight * ptr_Fl, Timetable * T) {
		return T->get_flight_time(T->get_flight_time(ptr_Fl->get_id())); //T - timetable
	}

extern "C" void print_timetable(Timetable * T) {
		T->print();
	}
