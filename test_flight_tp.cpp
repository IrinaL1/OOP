#include <cassert>
#include <cstdio>
#include <iostream>
#include "flight_tp.h"

void test_flight_tp() {
	//создаем рейс
	flight_between_two_points N1("Moscow", "Astrakan", 1, 1, 1260, 1380, 737); //Время отлета в минутах равно 1260 = 60 * 21, т е вылет в 21:00, прилет в 23:00
	assert(N1.get_start() == "Moscow");
	assert(N1.get_finish() == "Astrakhan");
	assert(N1.get_start_day() == 1);
	assert(N1.get_finish_day() == 1);
	assert(N1.get_start_time() == 1260);
	assert(N1.get_finish_time() == 1380);
	assert(N1.get_id() == 737);
	assert(N1.get_flight_time() == 120);
	cout <<"puhi" << N1.get_start_time() << '\n';
	//создаем обратный рейс
	flight_between_two_points * ptr_return_flight = 0;
	N1.return_flight(1, 1385, ptr_return_flight);
	flight_between_two_points N1_return = *ptr_return_flight;
	assert(N1_return.get_finish() == "Moscow");
	assert(N1_return.get_start() == "Astrakhan");
	cout << N1_return.get_start_time() << '\n';
	assert(N1_return.get_start_day() == 1);
	assert(N1_return.get_finish_day() == 2);
	assert(N1_return.get_start_time() == 1385);
	assert(N1_return.get_finish_time() == 65);
	assert(N1_return.get_id() == 737);
	assert(N1_return.get_flight_time() == 120);
	//проверяем операторы < и ==
	assert(&N1 < &N1_return == true);
	assert(&N1_return < &N1 == false);
	flight_between_two_points N2("Moscow", "Astrakan", 2, 1, 1250, 1380, 737);
	assert(&N1 < &N2 == true);
	assert(&N2 < &N1 == false);
	assert(&N1 == &N2 == false);
	flight_between_two_points N3("Volgograd", "Astrakan", 1, 1, 1260, 1380, 737);
	assert(&N1 < &N3 == false);
	assert(&N1 == &N3 == true);
}

int main () {
	test_flight_tp();
	return 0;
}
