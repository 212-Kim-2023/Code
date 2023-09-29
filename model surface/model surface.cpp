﻿#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

#define COUNT_BUMP 50

//212-Kim-Nayona
//class of points (bumps)
class Bump {
	friend class Surface;
private:
	double x0, y0;
	double sigma_x0, sigma_y0;
	double z0, var;
public:
	Bump(double xx = 0, double yy = 0, double zz = 0, double sigma_xx = 1, double sigma_yy = 1, double vv = 0) {
		x0 = xx;
		y0 = yy;
		sigma_x0 = sigma_xx;
		sigma_y0 = sigma_yy;
		z0 = zz;
		var = vv;
	}


	double Gauss(double x, double y) {
		for (int i = 0; i < COUNT_BUMP; i++) {
			double z = z0 * exp((-1) * (pow((-sin(var) * (x - x0) + cos(var) * (y - y0)), 2) / sigma_x0 + pow((cos(var) * (x - x0) + sin(var) * (y - y0)), 2) / sigma_y0));
			return z;
		}
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
public:
	Surface(double l = 30, double w = 30, double v = 0.5) {
		length = l;
		width = w;
		variance = v;
		for (int i = 0; i < COUNT_BUMP; i++) {
			double x_rand = rand() / double(RAND_MAX) * length;
			double y_rand = rand() / double(RAND_MAX) * width;
			double sigma_x_rand = rand() / double(RAND_MAX) * variance;
			double sigma_y_rand = rand() / double(RAND_MAX) * variance;
			double z_rand = rand() / double(RAND_MAX) * 60 - 30;
			double var_rand = rand() / double(RAND_MAX) * 10;

			Points[i] = new Bump(x_rand, y_rand, z_rand, sigma_x_rand, sigma_y_rand, var_rand);
		}
	}
	double heigth(double x, double y) {
		double z = 0;
		for (int i = 0; i < COUNT_BUMP; i++) {
			z += Points[i]->Gauss(x, y);
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
	Surface top(30,40,20);
	ofstream file("gnuplot.txt");
	top.print_file(file);
	file.close();
	return 0;

}