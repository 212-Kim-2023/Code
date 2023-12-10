#pragma once
#include "header.h"
#include "Surface.h"

class rover
{
private:
	int heading;
	int clearance; //просвет
	double alpha;
	double beta;
	int speed;
public:
	Surface top;
	rover(int head, int clear, double a, double b, int spd, Surface& t);
	rover();
	int sensor(int x0, int y0, int x, int y);
	int angles(int x0, int y0, int x, int y);
};

