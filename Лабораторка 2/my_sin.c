#include <stdio.h>
#include "my_sin.h"

double my_sin(double x, int terms_num) {
	double sum = 0; double prev_x = x;
	for (int i = 0; i < terms_num; i++) {
		sum += prev_x;
		prev_x = (prev_x * x * x * (-1)) / (2 * (i + 1) * (2 * (i + 1) + 1));
	}
	return sum;
}