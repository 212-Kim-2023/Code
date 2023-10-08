#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

#define COUNT_BUMP 2
#define COUNT_STONE 2
#define COUNT_LOG 1

//212-Kim-Nayona
//class of points (bumps)
class Bump {
	friend class Surface;
private:
	double x0, y0;
	double sigma_x0, sigma_y0;
	double z0, ang;
public:
	Bump(double xx = 0, double yy = 0, double zz = 0, double sigma_xx = 1, double sigma_yy = 1, double aa = 0) {
		x0 = xx;
		y0 = yy;
                z0 = zz;
		sigma_x0 = sigma_xx;
		sigma_y0 = sigma_yy;
		ang = aa;
	}


	double Gauss(double x, double y) {
                double z = z0 * exp((-1) * (pow((-sin(ang) * (x - x0) + cos(ang) * (y - y0)), 2) / sigma_x0 + pow((cos(ang) * (x - x0) + sin(ang) * (y - y0)), 2) / sigma_y0));
                return z;
	}
};

//212-Kim-Nayona
//class of stones
class Stone {
	friend class Surface;
private:
	double x0, y0, rad_stone;
public:
	Stone(double x = 0, double y = 0, double r = 0) {
		x0 = x;
		y0 = y;
		rad_stone = r;
	}
	double half_sphere(double x, double y) {
		double z = 0;
		if ((pow(rad_stone, 2) - pow((x - x0), 2) - pow((y - y0), 2)) >= 0) {
			z = sqrt(pow(rad_stone, 2) - pow((x - x0), 2) - pow((y - y0), 2));
		}
		return z;
	}
};

//212-Kim-Nayona
//class of logs
class Log {
	friend class Surface;
private:
	double x1, y1, x2, y2, rad_log;
public:
        Log(double x_1 = 1, double y_1 = 0, double x_2 = 0, double y_2 = 1, double r = 0) {
		x1 = x_1;
		y1 = y_1;
		x2 = x_2;
		y2 = y_2;
		rad_log = r;
	}
	double half_cylinder(double x, double y) {
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
};


//212-Kim-Nayona
//class of surface
class Surface {
private:
	double length;
	double width;
	double variance;
	Bump * Points[COUNT_BUMP];
	Stone * Points_stone[COUNT_STONE];
	Log * Points_log[COUNT_LOG];
public:
	Surface(double l = 30, double w = 30, double v = 1) {
		length = l;
		width = w;
		variance = v;
		for (int i = 0; i < COUNT_BUMP; i++) {
			double x_rand = rand() / double(RAND_MAX) * length;
			double y_rand = rand() / double(RAND_MAX) * width;
                        double sigma_x_rand = rand() / double(RAND_MAX) * variance + 0.1;
                        double sigma_y_rand = rand() / double(RAND_MAX) * variance + 0.1;
			double z_rand = rand() / double(RAND_MAX) * 50 - 25;
			double ang_rand = rand() / double(RAND_MAX) * 10;

			Points[i] = new Bump(x_rand, y_rand, z_rand, sigma_x_rand, sigma_y_rand, ang_rand);
		}
		for (int i = 0; i < COUNT_STONE; i++) {
			double x_rand = rand() / double(RAND_MAX) * length;
			double y_rand = rand() / double(RAND_MAX) * width;
			double rad = rand() / double(RAND_MAX) * 7;

			Points_stone[i] = new Stone(x_rand, y_rand, rad);
		}
		for (int i = 0; i < COUNT_LOG; i++) {
			double x1_rand = rand() / double(RAND_MAX) * length;
			double y1_rand = rand() / double(RAND_MAX) * width;
			double x2_rand = rand() / double(RAND_MAX) * length;
			double y2_rand = rand() / double(RAND_MAX) * width;
			double rad = rand() / double(RAND_MAX) * 5;

			Points_log[i] = new Log(x1_rand, y1_rand, x2_rand, y2_rand, rad);
		}
	}
	double heigth(double x, double y) {
		double z = 0;
		for (int i = 0; i < COUNT_BUMP; i++) {
			z += Points[i] -> Gauss(x, y);
		}

		for (int i = 0; i < COUNT_STONE; i++) {
			z += Points_stone[i]->half_sphere(x, y);
		}	

		for (int i = 0; i < COUNT_LOG; i++) {
			z += Points_log[i]->half_cylinder(x, y);
		}
		return z;
	}
	void print_file(ofstream& file) {
		for (double i = 0; i < length; i += 0.3) {
			for (double j = 0; j < width; j += 0.3) {
				file << i <<" " << j <<" "<< heigth(i, j) << endl;
			}
		}
	}
};



int main(void)
{
	srand(time(NULL));
	Surface top(50, 50, 20);
	ofstream file("gnuplot.txt");
	top.print_file(file);
	file.close();
	return 0;
}
