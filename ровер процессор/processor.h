#include "header.h"
#include "rover.h"
#include <queue>

class processor
{
private:
	int A1;
	int A2;
	int B1;
	int B2;
	rover truck;
public:
	processor(int a1, int a2, int b1, int b2, rover& tr);
	processor();
	void route();
};

