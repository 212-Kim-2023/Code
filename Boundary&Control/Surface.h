#include "header.h"
#include "Bump.h"
#include "Stone.h"
#include "Log.h"

class Surface {
private:
	double length;
	double width;
	double variance;
	Bump* Points[COUNT_BUMP];
	Stone* Points_stone[COUNT_STONE];
	Log* Points_log[COUNT_LOG];
public:
	Surface(double l = 30, double w = 30, double v = 1);
	double heigth(double x, double y);
	void print_file();
};