#include "header.h"
#include "Control.h"

class Boundary
{
private:
	string comand;
	string log_control;
	string log_boundary;
	Control control;
	int time;
	int data;
public:
	Boundary(string com, string logc, string logb, int tm, int dt);
	void boundary_func();
};