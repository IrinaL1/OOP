#include <cstdio>
#include <string>

#include "point.h"

Point::Point (std::string name){

	this->name = name;

}

Point::~Point() {

	name.clear();
	bound_time.clear();

}
