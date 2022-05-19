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
//		cout << "Start" << '\n';
		ifstream file_ptr(filename);
		//file_ptr.open(filename);
		if (!file_ptr) cout << "No such file" << '\n';
//		cout << "Start" << '\n';
		Timetable * T = new Timetable;
		//считываю названия эропортов
		std::string buf;
		std::vector<std::string> FilePoints;
//		cout << "Start" << '\n';
		if(file_ptr.is_open()) 
			while (std::getline(file_ptr, buf)){
				if(buf == ";") break;
				FilePoints.push_back(buf);
			}
//		cout << "ira"<<endl;
		//if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n'; //считываю разделитель

		//создаю аэропорты-объекты
		std::map<std::string, Point> airports;
		std::string name_1;	//аэропорт, для которого задаю связи
		std::string name_2; //связанные аэропорты
		int min_time;
		int max_time;
		std::map <std::string, std::pair<int, int>> bound_time;
		while(file_ptr.peek() != '.') {
			if(!std::getline(file_ptr, name_1)) cout << "Error reading" << '\n';
			while(file_ptr.peek() != ';' && file_ptr.peek() != '.') {
				if(!std::getline(file_ptr, name_2)) cout << "Error reading" << '\n';
				if(!std::getline(file_ptr, buf)) 
					cout << "Error reading min_time airports" << '\n';
				else{
//					cout << buf<<endl;
					min_time = stoi(buf);
					if(min_time <= 20)
						cout << "Incorrect min_time" << '\n';
				}
				if(!std::getline(file_ptr, buf)) 
					cout << "Error reading max_time airports" << '\n';
				else{
//					cout << buf<<endl;
					max_time = stoi(buf);
					if(max_time <= 20 || max_time < min_time)
						cout << "Incorrect max_time" << '\n';
				}
				bound_time.emplace(name_2, make_pair(min_time, max_time));			
			}
			if(file_ptr.peek() == '.') break;
			std::getline(file_ptr, buf);//считываю разделитель
				airports.emplace(name_1, Point(name_1, bound_time));
		}
		
		if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n'; //считываю разделитель
//		cout << "After airports" << '\n';
		//задаю рейсы
		//name_1 - город отправления
		//name_2 - буфер, в который считываю следующие города в рейсе
		std::vector<std::string> FlightPoints;
		std::vector<struct time> FlightTime;
		struct time BufTime;
		int id;

		while(!file_ptr.eof()){
			if(!std::getline(file_ptr, name_1)) cout << "Error reading or End of file" << '\n';
//			cout << name_1<<endl;
//			cout << "name_1" << '\n';
			FlightPoints.push_back(name_1);
//			cout << FlightPoints[0] << endl;
			//считываю города в рейсе
			while(file_ptr.peek() != ';' && std::getline(file_ptr, name_2)){
//				cout << name_2 << endl;
				FlightPoints.push_back(name_2);
				}
			if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n'; //считываю разделитель
			if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
			else id = stoi(buf);
//			cout << buf <<endl;
			while(file_ptr.peek() != ':' && std::getline(file_ptr, buf)){
//				cout << buf <<endl;
				BufTime.start_day = stoi(buf);
				if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
//				cout << buf <<endl;
				BufTime.finish_day = stoi(buf);
				if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
//				cout << buf <<endl;
                BufTime.start_time = stoi(buf);
				if(!std::getline(file_ptr, buf)) cout << "Error reading" << '\n';
//				cout << buf <<endl;
                BufTime.finish_time = stoi(buf);
				FlightTime.push_back(BufTime);
				std::getline(file_ptr, buf);//считываю разделитель
			
//				cout << buf << endl;
				if (buf[0] == ':') break;
     		}

			if(FlightPoints.size() == 2){ 
				FlightBetweenTwoPoints F (FlightPoints, FlightTime, id);
				FlightPoints.clear();
//				cout << FlightPoints[0] << endl;
				FlightTime.clear();
				T->push_node(&F);
			}
			else {
//				cout << FlightPoints[0] << endl;
				CyclicFlight F (FlightPoints, FlightTime, id);
				FlightPoints.clear();
				FlightTime.clear();
				T->push_node(&F);
			}
		//	if(!std::getline(file_ptr, buf)) cout << "Error reading or End of file" << '\n'; //считываю разделитель
//			cout << buf <<endl;
//			cout << "After Moscow Astr" << '\n';
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

