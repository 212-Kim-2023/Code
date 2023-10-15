#include "Stone.h"

Stone::Stone(double x, double y, double r) {
	x0 = x;
	y0 = y;
	rad_stone = r;
}

double Stone::half_sphere(double x, double y) {
	double z = 0;
	if ((pow(rad_stone, 2) - pow((x - x0), 2) - pow((y - y0), 2)) >= 0) {
		z = sqrt(pow(rad_stone, 2) - pow((x - x0), 2) - pow((y - y0), 2));
	}
	return z;
}