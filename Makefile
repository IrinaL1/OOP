test_flight_tp: *.h *.cpp
	g++ -g -Wall -Wextra -O0 flight.cpp flight_tp.cpp cyclic_flight.cpp point.cpp test_flight.cpp timetable.cpp -o test_flight_tp
