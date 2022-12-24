#include <stdio.h>
#include "my_exp.h"

double my_exp(double x, int terms_num) {
	double sum = 1; double prev_x = 1;
	for (int i = 1; i < terms_num; i++) {
		prev_x = prev_x * x / i;
		sum += prev_x;
	}
	return sum;
}