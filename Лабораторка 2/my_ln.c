#include <stdio.h>
#include "my_ln.h"

double my_ln(double x, int terms_num) {
	x--;
	double sum = 0; double prev_x = x;
	for (int i = 1; i <= terms_num; i++) {
		sum += prev_x / i;
		prev_x *= (-x);
	}
	return sum;
}