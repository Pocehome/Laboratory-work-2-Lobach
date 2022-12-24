#include <stdio.h>
#include "my_cos.h"

double my_cos(double x, int terms_num) {
	double sum = 0; double prev_x = 1;
	for (int i = 1; i < terms_num; i++) {
		sum += prev_x;
		prev_x = ((prev_x * x * x * (-1)) / (2 * i * (2 * i - 1)));
	}
	return sum;
}