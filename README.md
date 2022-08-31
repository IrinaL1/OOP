# OOP

Описание приложения:
Приложение хранит данные о маршрутах авиарейсов, совершаемых авиакомпанией. Все рейсы выполняются регулярно каждую неделю по одним и тем же маршрутам. Каждый самолёт в одно и то же время может находиться только в одном рейсе.

Класс Flight. Его наследники FlightBetweenTwoPoints и CyclicFlight. Класс Point. Класс Timetable.
Print выводит расписание на неделю

Односвязный список

Создавать библиотеку с помощью команды:
g++ -fPIC -shared -g -O0 -o lib.so extern.cpp point.cpp timetable.cpp flight.cpp flight_tp.cpp cyclic_flight.cpp
запускать программу с помощью: python3 main.py
вводить ./airports.txt или airports.txt
