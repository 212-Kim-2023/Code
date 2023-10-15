#include "header.h"
#include "Control.h"

class Boundary
{
private:
	string comand;
	string log_control;
	string log_boundary;
public:
	Boundary(string com, string logc, string logb);
	void boundary_func();
};