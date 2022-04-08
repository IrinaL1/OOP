test_flight_tp: *.h *.cpp
	g++ flight.cpp flight_tp.cpp point.cpp test_flight.cpp timetable.cpp -o test_flight_tp
