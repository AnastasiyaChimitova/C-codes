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
	cout << "������� ��������� �������� �0" << endl;
	cin >> x1;
	cout << "������� ������������ �" << endl;
	cin >> eps;
	do
	{
		x0 = x1;
		x1 = fun(x0);
		i = i + 1;
	} while (fabs(x1 - x0) > eps);
	//cout << "������� = " << fun(x0) << endl;
	//cout << "x0 = " << x0 << endl;
	cout << "������ ��������� = " << x1 << endl;
	cout << "���������� �������� = " << i << endl;
	system("pause");
}