#pragma once
#include "header.h"

class Log
{
	friend class Surface;
private:
	double x1, y1, x2, y2, rad_log;
public:
	Log(double x_1 = 1, double y_1 = 0, double x_2 = 0, double y_2 = 1, double r = 0);
	double half_cylinder(double x, double y);
};