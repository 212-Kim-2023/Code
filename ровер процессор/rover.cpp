#include "rover.h"

rover::rover(int head, int clear, double a, double b, int spd, Surface& t) {
	heading = head;
	clearance = clear;
	alpha = a;
	beta = b;
	speed = spd;
	top = t;
}

rover::rover() {
	heading = 0;
	clearance = 0;
	alpha = 0;
	beta = 0;
	speed = 0;
}

int rover::angles(int x0, int y0, int x, int y) {
	int i, j;
	int xt = (0 < x - x0) - (0 > x - x0); 
	int yt = (0 < y - y0) - (0 > y - y0);
	if (xt != 0 && yt != 0) {
		for (i = x0; i <= x; i += xt) {
			for (j = x0; j <= x; j += xt) {
				if (abs(top.Pixel[i][j] - top.Pixel[i + xt][j + yt]) > alpha) {
					return 0;
				}
				if (abs(top.Pixel[i][j] - top.Pixel[i - xt][j - yt]) > alpha) {
					return 0;
				}
				if (abs(top.Pixel[i][j] - top.Pixel[i + xt][j - yt]) > beta) {
					return 0;
				}
				if (abs(top.Pixel[i][j] - top.Pixel[i - xt][j + yt]) > beta) {
					return 0;
				}
			}
		}
	}
	if (yt == 0) {
		for (i = x0; i <= x; i += xt) {
			if (abs(top.Pixel[i][y] - top.Pixel[i + xt][y]) > alpha) {
				return 0;
			}
			if (abs(top.Pixel[i][y] - top.Pixel[i - xt][y]) > alpha) {
				return 0;
			}
			if (abs(top.Pixel[i][y] - top.Pixel[i][y + 1]) > beta) {
				return 0;
			}
			if (abs(top.Pixel[i][y] - top.Pixel[i][y - 1]) > beta) {
				return 0;
			}
		}
	}
	if (xt == 0) {
		for (j = y0; j <= y; j += yt) {
			if (abs(top.Pixel[x][j] - top.Pixel[x][j + yt]) > alpha) {
				return 0;
			}
			if (abs(top.Pixel[x][j] - top.Pixel[x][j - yt]) > alpha) {
				return 0;
			}
			if (abs(top.Pixel[x][j] - top.Pixel[x + 1][j]) > beta) {
				return 0;
			}
			if (abs(top.Pixel[x][j] - top.Pixel[x - 1][j]) > beta) {
				return 0;
			}
		}
	}
	return 1;
}

int rover::sensor(int x0, int y0, int x, int y) {
	int i, j;
	int xt = (0 < x - x0) - (0 > x - x0);
	int yt = (0 < y - y0) - (0 > y - y0);
	if (yt == 0) {
		for (i = x0; i <= x; i += xt) {
			if (top.Pixel[i + xt][y] - top.Pixel[i][y] > clearance) {
				return 0;
			}
			if (top.Pixel[i + xt][y - 1] - top.Pixel[i][y - 1] > clearance) {
				return 0;
			}
			if (top.Pixel[i + xt][y + 1] - top.Pixel[i][y + 1] > clearance) {
				return 0;
			}
		}
	}
	if (xt == 0) {
		for (j = y0; j <= y; j += yt) {
			if (top.Pixel[x][j + yt] - top.Pixel[x][j] > clearance) {
				return 0;
			}
			if (top.Pixel[x - 1][j + yt] - top.Pixel[x - 1][j] > clearance) {
				return 0;
			}
			if (top.Pixel[x + 1][j + yt] - top.Pixel[x + 1][j] > clearance) {
				return 0;
			}
		}
	}
	if (xt != 0 && yt != 0) {
		for (i = x0; i <= x; i += xt) {
			for (j = x0; j <= x; j += xt) {
				if (top.Pixel[i - xt][j] - top.Pixel[i][j + yt] > clearance) {
					return 0;
				}
				if (top.Pixel[i][j] - top.Pixel[i + xt][j + yt] > clearance) {
					return 0;
				}
				if (top.Pixel[i][j - yt] - top.Pixel[i + yt][j] > clearance) {
					return 0;
				}
			}
		}
	}
	return 1;
}