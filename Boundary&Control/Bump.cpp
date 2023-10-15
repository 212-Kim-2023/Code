#include "Bump.h"

Bump::Bump(double xx, double yy, double zz, double sigma_xx, double sigma_yy, double aa) {
	x0 = xx;
	y0 = yy;
	z0 = zz;
	sigma_x0 = sigma_xx;
	sigma_y0 = sigma_yy;
	ang = aa;
}

double Bump::Gauss(double x, double y) {
	for (int i = 0; i < COUNT_BUMP; i++) {
		double z = z0 * exp((-1) * (pow((-sin(ang) * (x - x0) + cos(ang) * (y - y0)), 2) / sigma_x0 + pow((cos(ang) * (x - x0) + sin(ang) * (y - y0)), 2) / sigma_y0));
		return z;
	}
}
