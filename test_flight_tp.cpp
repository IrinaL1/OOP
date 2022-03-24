#include <cassert>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>

#include "flight_tp.h"
#include "flight.h"
#include "point.h"

void test_flight_tp(int Num_air) {

	//считываю рейсы из файлы
	struct time * Time = new struct time[Num_air-1];
	string * Points = new string[Num_air];
	int Num_P = 0;
	int Num_F = 0; //Количество рейсов в файле
	std::ifstream file("input.txt");
	file >> Num_F;
	FlightBetweenTwoPoints **ArrTpPtr = new FlightBetweenTwoPoints*[Num_F];

	for(int i = 0; !file.eof(); i++){

		file >> Num_P; //Узнали сколько пунктов
		//Считываем пункты и заполняем структуры времени
		for (int j = 0; i < Num_P; i++) {
			file >> *(Points + i);		
		}
		for (int j = 0; i < Num_P - 1; i++) {
			file >> (Time + i)->start_day;
			file >> (Time + i)->finish_day;
			file >> (Time + i)->start_time;
			file >> (Time + i)->finish_time; 
		}
		//можем создать объект рейс
		if (Num_P == 2) {
			*(*ArrTpPtr + i) = FlightBetweenTwoPoints(Num_P, Points, Time);
		}
	}

	assert((**ArrTpPtr).get_start() == "Moscow");
	assert((**ArrTpPtr).get_finish() == "Astrakhan");
	assert((**ArrTpPtr).get_start_day() == 1);
	assert((**ArrTpPtr).get_finish_day() == 1);
	assert((**ArrTpPtr).get_start_time() == 1260);
	assert((**ArrTpPtr).get_finish_time() == 1380);
	//assert(*arr_tpf.get_id() == 737);
	assert((**ArrTpPtr).get_flight_time() == 120);
	//создаем обратный рейс
	FlightBetweenTwoPoints * ptr_return_flight = 0;
	(**ArrTpPtr).return_flight(1, 1385);
	FlightBetweenTwoPoints N1_return = *ptr_return_flight;
	assert(N1_return.get_finish() == "Moscow");
	assert(N1_return.get_start() == "Astrakhan");
	cout << N1_return.get_start_time() << '\n';
	assert(N1_return.get_start_day() == 1);
	assert(N1_return.get_finish_day() == 2);
	assert(N1_return.get_start_time() == 1385);
	assert(N1_return.get_finish_time() == 65);
	//assert(N1_return.get_id() == 737);
	assert(N1_return.get_flight_time() == 120);
	//проверяем операторы < и ==
	assert(**ArrTpPtr < N1_return == true);
	assert(N1_return < **ArrTpPtr == false);
	assert(**ArrTpPtr < **(ArrTpPtr + 1) == true);
	assert(**(ArrTpPtr + 1) < **ArrTpPtr == false);
	assert(**ArrTpPtr == **(ArrTpPtr + 1) == false);
}

int main () {
	//считываю аэропорты (Point)
	std::ifstream file("airpots.txt");
	std::map<std::string, Point> airpots;
	//создаю map, где ключ = название города, значение = объект Point
	int Num_air = 0; //количество аэропортов
	while(!file.eof()){
		std::string key;
		file >> key;
		airpots[key] = Point(key);
		Num_air++;
	}
	file.close();
	
	test_flight_tp(Num_air);
	return 0;
}
