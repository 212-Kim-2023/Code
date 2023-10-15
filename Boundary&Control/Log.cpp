#include "Log.h"

Log::Log(double x_1, double y_1, double x_2, double y_2, double r) {
	x1 = x_1;
	y1 = y_1;
	x2 = x_2;
	y2 = y_2;
	rad_log = r;
}

double Log::half_cylinder(double x, double y) {
	double t;
	double z;
	t = pow((rad_log), 2) - pow((y - (x - x1) * (y2 - y1) / (x2 - x1) - y1), 2);
	if (t >= 0 && abs(y - ((x1 - x2) * x / (y2 - y1)) - (y1 + y2) / 2 + (x1 - x2) * (x1 + x2) / (2 * (y2 - y1))) <= sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) / 2) {
		z = sqrt(t);
	}
	else {
		z = 0;
	}
	return z;
}