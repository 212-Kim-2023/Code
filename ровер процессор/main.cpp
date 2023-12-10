#include "header.h"
#include "Boundary.h"

int main(void)
{
	string line, str, comand, log_boundary, log_control;
	int time, data;
	ifstream config("config.txt"); 
	while (getline(config, line)) {
		istringstream iss(line);
		iss >> str;
		if (str == "comand_file") {
			iss >> str;
			if (str == "=") {
				iss >> comand;
			}
		}

		if (str == "log_boundary") {
			iss >> str;
			if (str == "=") {
				iss >> log_boundary;
			}
		}

		if (str == "log_control") {
			iss >> str;
			if (str == "=") {
				iss >> log_control;
			}
		}

		if (str == "time") {
			iss >> str;
			if (str == "=") {
				iss >> time;
			}
		}

		if (str == "data") {
			iss >> str;
			if (str == "=") {
				iss >> data;
			}
		}
	}
	Boundary* bound = new Boundary(comand, log_control, log_boundary, time, data);
	(*bound).boundary_func();
	delete bound;
	return 0;
}