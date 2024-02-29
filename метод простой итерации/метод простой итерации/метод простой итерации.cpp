#include <iostream>
#include <math.h>
using namespace std;

double fun(double x)
{
	return (8 * log(x) + 8) / 5;
	//return (-pow(x,3)+0.2*pow(x,2)+1.4)/0.5;
}

void main()
{
	double x0, x1, eps; int i = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите начальное значение Х0" << endl;
	cin >> x1;
	cout << "Введите погрешнность Е" << endl;
	cin >> eps;
	do
	{
		x0 = x1;
		x1 = fun(x0);
		i = i + 1;
	} while (fabs(x1 - x0) > eps);
	//cout << "Функция = " << fun(x0) << endl;
	//cout << "x0 = " << x0 << endl;
	cout << "Корень уравнения = " << x1 << endl;
	cout << "Количество итераций = " << i << endl;
	system("pause");
}