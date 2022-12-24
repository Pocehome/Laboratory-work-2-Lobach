#pragma once

void print_table(double x, double step, int terms_num, int rows, double(*MyFuncPointer)(double x, int terms_num), double(*MathFuncPointer)(double x));
void print_table_line(int len, int fist_last);