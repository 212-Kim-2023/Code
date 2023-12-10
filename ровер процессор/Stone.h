#pragma once
#include "header.h"

class Stone
{
	friend class Surface;
private:
	double x0, y0, rad_stone;
public:
	Stone(double x = 0, double y = 0, double r = 0);
	double half_sphere(double x, double y);
};