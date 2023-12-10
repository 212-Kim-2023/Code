#include "Surface.h"

Surface::Surface() {
	length= 0;
	width = 0;
	Pixel[0][0] = 0;
}

Surface::Surface(double l, double w) {
	length = l;
	width = w;
	Pixel[0][0] = 0;

}

void Surface::random_generating(int c_b, int c_s, int c_l) {
	srand(time(NULL));
	for (int i = 0; i < c_b; i++) {
		double x_rand = rand() / double(RAND_MAX) * length;
		double y_rand = rand() / double(RAND_MAX) * width;
		double sigma_x_rand = rand() / double(RAND_MAX) * 20 + 0.1;
		double sigma_y_rand = rand() / double(RAND_MAX) * 20  + 0.1;
		double z_rand = rand() / double(RAND_MAX) * 10 - 5;
		double ang_rand = rand() / double(RAND_MAX) * 10;

		B.push_back(Bump(x_rand, y_rand, z_rand, sigma_x_rand, sigma_y_rand, ang_rand));
	}
	for (int i = 0; i < c_s; i++) {
		double x_rand = rand() / double(RAND_MAX) * length;
		double y_rand = rand() / double(RAND_MAX) * width;
		double rad = rand() / double(RAND_MAX) * 3;

		S.push_back(Stone(x_rand, y_rand, rad));
	}
	for (int i = 0; i < c_l; i++) {
		double x1_rand = rand() / double(RAND_MAX) * length;
		double y1_rand = rand() / double(RAND_MAX) * width;
		double x2_rand = rand() / double(RAND_MAX) * length;
		double y2_rand = rand() / double(RAND_MAX) * width;
		double rad = rand() / double(RAND_MAX) * 5;

		L.push_back(Log(x1_rand, y1_rand, x2_rand, y2_rand, rad));
	}
}

void Surface::calculate() {
	int k;
	double h;
	ofstream file("Surface.txt");
	for (int i = 0; i < 120; i++) {
		for (int j = 0; j < 120; j++) {
			double x = i * length / 120;
			double y = j * width / 120;
			h = 0;
			for (k = 0; k < B.size(); k++) {
				h += B[k].Gauss(x, y);
			}
			for (k = 0; k < S.size(); k++) {
				h += S[k].half_sphere(x, y);
			}
			for (k = 0; k < L.size(); k++) {
				h += L[k].half_cylinder(x, y);
			}
			file << x << " " << y << " " << h << endl;
			Pixel[i][j] = 128 * h / sqrt(length * width);
		}
		file << endl;
	}
}

