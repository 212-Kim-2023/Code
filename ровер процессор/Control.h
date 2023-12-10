#include "header.h"
#include "Surface.h"
#include "rover.h"
#include "processor.h"

class Control
{
private:
	string log_control;
	int time;
	int data;
	Surface* top;
	rover* truck;
	processor* convert;
public:
	Control();
	Control(string logc, int tm, int dt);
	void control_func(double x, double y, int c_b, int c_s, int c_l, int heading, int clearance, double alpha, double beta, int speed, int A1, int A2, int B1, int B2);
};