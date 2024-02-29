#include <iostream>
#include <math.h>
using namespace std;

float f(float x)
{
	//return pow(x, 3) - 0.2*pow(x, 2) + 0.5*x - 1.4;
	return (5 * x) - (8 * log(x)) - 8;
}
void main()
{
	float a, b, c, h, p, E;
	setlocale(LC_ALL, "rus");
	cout << "Введите значение a: ";
	cin >> a;
	cout << "Введите значение b: ";
	cin >> b;
	cout << "Задайте погрешность е: ";
	cin >> E;
	do
	{
		c = (a + b) / 2;
		if (f(c)*f(b) < 0)
			a = c;
		else b = c;
	} while (fabs(b - a) > E);

	p = (a + b) / 2;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "Приближенное значение P = " << p << endl;
	cout << "F(p) = " << f(p) << endl;
	system("pause");
}
