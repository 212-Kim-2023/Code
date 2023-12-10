#include "Control.h"

Control::Control() {
	data = 0;
	time = 0;
}

Control::Control(string logc, int tm, int dt) {
	log_control = logc;
	time = tm;
	data = dt;
}

void Control::control_func(double x, double y, int c_b, int c_s, int c_l, int heading, int clearance, double alpha, double beta, int speed, int A1, int A2, int B1, int B2) {
	ofstream logc(log_control);
	logc << "Created surface" << endl;
	top = new Surface(x, y);
	logc << "Created random generating" << endl;
	(*top).random_generating(c_b, c_s, c_l);
	logc << "Created calculate" << endl;
	(*top).calculate();
	logc << "Created rover" << endl;
	truck = new rover(heading, clearance, alpha, beta, speed, *top);
	logc << "Created processor" << endl;
	convert = new processor(A1, A2, B1, B2, *truck);
	(*convert).route();
	delete top;
	delete truck;
	delete convert;
}