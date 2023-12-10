#pragma once
#include "header.h"
#include <vector>
#include "Bump.h"
#include "Stone.h"
#include "Log.h"

class Surface {
private:
	double length;
	double width;
public:
	vector <Bump> B;
	vector <Stone> S;
	vector <Log> L;
	int Pixel[120][120];
	Surface();
	Surface(double l, double w);
	void random_generating(int c_b, int c_s, int c_l);
	void calculate();
};