#include "Boundary.h"

Boundary::Boundary(string com, string logc, string logb){
	comand = com;
	log_control = logc;
	log_boundary = logb;
}

void Boundary::boundary_func() {
	string str, line;
	int l, w, v;
	int k = 0;
	Control Cont(log_control);
	ofstream logb(log_boundary);
	ifstream com(comand);
	while (getline(com, line)) {
		istringstream iss(line);
		iss >> str;
		if (str == "Surface") {
			iss >> l;
			iss >> w;
			iss >> v;
			logb << "Surface is sent to created" << endl;
			k++;
		}
		if (str == "print_file") {
			logb << "The function of printing points to file is sent to created" << endl;
			k++;
		}
	}
	if (k < 2) {
		logb << "Error: in comand file not enough comands" << endl;
	}
	Cont.control_func();
}