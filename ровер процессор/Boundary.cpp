#include "Boundary.h"

Boundary::Boundary(string com, string logc, string logb, int tm, int dt) {
	comand = com;
	log_control = logc;
	log_boundary = logb;
	time = tm;
	data = dt;
	control = Control(logc, tm, dt);
}

void Boundary::boundary_func() {
	string str, line;
	double x = 10, y = 10;
	double alpha = 0, beta = 0;
	int c_b = 0, c_s = 0, c_l = 0;
	int heading = 0, clearance = 0, speed = 0, A1 = 0, A2 = 0, B1 = 0, B2 = 0;
	int k = 0;
	ofstream logb(log_boundary);
	ifstream com(comand);
	while (getline(com, line)) {
		istringstream iss(line);
		iss >> str;
		if (str == "Surface") {
			iss >> x;
			iss >> y;
			logb << "Surface is sent to created" << endl;
			k++;
		}
		if (str == "random_generating") {
			iss >> c_b;
			iss >> c_s;
			iss >> c_l;
			logb << "Sent random generating" << endl;
			k++;
		}
		if (str == "calculate") {
			logb << "Sent calculate" << endl;
			k++;
		}
		if (str == "rover") {
			iss >> heading;
			iss >> clearance;
			iss >> alpha;
			iss >> beta;
			iss >> speed;
			logb << "Sent rover" << endl;
			k++;
		}
		if (str == "processor") {
			iss >> A1;
			iss >> A2;
			iss >> B1;
			iss >> B2;
			logb << "Sent processor" << endl;
			k++;
		}
	}
	if (k < 5) {
		logb << "Error: in comand file not enough comands" << endl;
	}
	control.control_func(x, y, c_b, c_s, c_l, heading, clearance, alpha, beta, speed, A1, A2, B1, B2);
}