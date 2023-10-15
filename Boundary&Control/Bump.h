#include "header.h"

class Bump
{
	friend class Surface;
private:
	double x0, y0;
	double sigma_x0, sigma_y0;
	double z0, ang;
public:
	Bump(double xx = 0, double yy = 0, double zz = 0, double sigma_xx = 1, double sigma_yy = 1, double aa = 0);
	double Gauss(double x, double y);
};

