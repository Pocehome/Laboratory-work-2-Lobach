#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "print_table.h"

void print_table_line(int len, int first_last) {
	if (first_last == 1) {
		printf_s("+");
		for (int i = 0; i < len; i++) {
			if ((i == 15) || ((i - 15) % 24 == 0)) {
				printf_s("+");
				continue;
			}

			printf_s("-");
		}
		printf_s("+\n");
	}
	else {
		printf_s("|");
		for (int i = 0; i < len; i++) {
			if ((i == 15) || ((i - 15) % 24 == 0)) {
				printf_s("|");
				continue;
			}

			printf_s("-");
		}
		printf_s("|\n");
	}
}

void print_table(double x, double step, int terms_num, int rows, double(*MyFuncPointer)(double x, int terms_num), double(*MathFuncPointer)(double x)) {
	double max_err = 0;
	double max_err_x = 0;
	print_table_line(87, 1);
	printf_s("|\tx\t|\tf(x)\t\t|\tf_pr(x)\t\t|\tErr(x)\t\t|\n");
	for (int row = 0; row < rows; row++) {
		double x_now = x + row * step;
		double math_func_res = (*MathFuncPointer)(x_now);
		double my_func_res = (*MyFuncPointer)(x_now, terms_num);
		double err_now = fabs(math_func_res - my_func_res);

		print_table_line(87, 0);
		printf_s("|%14.14g |%22.6g |%22.6g |%22e |\n", x_now, math_func_res, my_func_res, err_now);
		if (err_now > max_err) {
			max_err = err_now;
			max_err_x = x_now;
		}
	}
	print_table_line(87, 1);
	printf_s("Максимальная погрешность = %e, при x = %.14g\n\n", max_err, max_err_x);
}