#include "Control.h"

Control::Control(string logc) {
	log_control = logc;
}

void Control::control_func() {
	ofstream logc(log_control);
	logc << "Created Surface" << endl;
	Surface top(50, 50, 20);
	logc << "Created the function of printing points to file" << endl;
	top.print_file();
}