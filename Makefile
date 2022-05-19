airports: *.h flight.cpp flight_tp.cpp cyclic_flight.cpp point.cpp test_flight.cpp timetable.cpp	
	g++ -fPIC -shared -g -O0 -o libmain.so flight.cpp flight_tp.cpp cyclic_flight.cpp point.cpp test_flight.cpp timetable.cpp
