#include <cstdio>
#include <string>
#include <map>
#include <cstring>

#ifndef POINT_H_
#define POINT_H_

class Point {

	std::string name;
	std::map <std::string, std::pair<int, int>> bound_time;
	
	public:
	Point(std::string name, std::map <std::string, std::pair<int, int>> bound_time);
	~Point();
};

#endif
