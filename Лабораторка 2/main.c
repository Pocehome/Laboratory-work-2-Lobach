#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "my_exp.h"
#include "my_sin.h"
#include "my_cos.h"
#include "my_ln.h"
#include "print_table.h"

void main() {
	setlocale(LC_ALL, "Russian");

	int id_operation = 1;
	double x;
	int terms_num;
	double step;
	int rows;

	printf_s("������ ��������:\n1) ����� �������� e^x\n2) ����� �������� sin(x)\n");
	printf("3) ����� �������� cos(x)\n4) ����� �������� ln(x), ��� x = (0, 2]\n");
	printf_s("��� ���������� ������ ������� � ���� '����� ��������' 0\n\n");

	while (id_operation != 0) {
		printf_s("������� ����� ��������: ");
			scanf_s("%d", &id_operation);

		double (*MyFuncPointer) (double x, int terms_num);
		double (*MathFuncPointer) (double x);

		switch (id_operation) {
			case 0:
				printf_s("���������� ������\n");
				continue;
			case 1:
				printf_s("1) ����� �������� e^x\n");
				MyFuncPointer = &my_exp;
				MathFuncPointer = &exp;
				break;
			case 2:
				printf_s("2) ����� �������� sin(x)\n");
				MyFuncPointer = &my_sin;
				MathFuncPointer = &sin;
				break;
			case 3:
				printf_s("3) ����� �������� cos(x)\n");
				MyFuncPointer = &my_cos;
				MathFuncPointer = &cos;
				break;
			case 4:
				printf_s("4) ����� �������� ln(x), ��� x = (0, 2]\n");
				MyFuncPointer = &my_ln;
				MathFuncPointer = &log;
				break;
			default:
				printf_s("�������� ����� ��������\n\n");
				continue;
			}

		printf_s("������� �������� ��� �������: ");
		scanf_s("%lf", &x);

		printf_s("������� ����������� (���������� ��������� � ���� �������): ");
		scanf_s("%d", &terms_num);

		//printf_s("������� �������: %lf \n", (*MyMathFuncPointer)(x, terms_num));
		//printf_s("������� �� math.h: %lf \n", (*OriginalMathFuncPointer)(x));

		printf_s("������� ��� ���������� x: ");
		scanf_s("%lf", &step);

		printf_s("������� ���������� ����� � �������: ");
		scanf_s("%d", &rows);

		print_table(x, step, terms_num, rows, MyFuncPointer, MathFuncPointer);
	}
}