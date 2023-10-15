#include "Surface.h"

Surface::Surface(double l, double w, double v) {
	length = l;
	width = w;
	variance = v;
	srand(time(NULL));
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

double Surface::heigth(double x, double y) {
	double z = 0;
	for (int i = 0; i < COUNT_BUMP; i++) {
		z += Points[i]->Gauss(x, y);
	}

	for (int i = 0; i < COUNT_STONE; i++) {
		z += Points_stone[i]->half_sphere(x, y);
	}

	for (int i = 0; i < COUNT_LOG; i++) {
		z += Points_log[i]->half_cylinder(x, y);
	}
	return z;
}

void Surface::print_file() {
	ofstream file("gnuplot.txt");
	for (double i = 0; i < length; i += 0.3) {
		for (double j = 0; j < width; j += 0.3) {
			file << i << " " << j << " " << heigth(i, j) << endl;
		}
	}
}
