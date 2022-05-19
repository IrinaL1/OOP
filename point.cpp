#include <cstdio>
#include <string>

#include "point.h"

Point::Point (std::string name, std::map <std::string, std::pair<int, int>> bound_time){

	this->name = name;
	this->bound_time = bound_time;
}

Point::~Point(){

	name.clear();
	bound_time.clear();

}

