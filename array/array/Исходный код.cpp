#include <iostream>
#include <time.h>
using namespace std;
// Упорядочить элементы матрицы в столбцах по убыванию

void main()
{
	const int n = 5;
	float a[n][n], max; int i, j, p, m;
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	cout << " Исходная матрица: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << endl;
		for (j = 0; j < n; j++)
		{
			a[i][j] = (rand() % 1000) / 100.0;
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
	cout << "" << endl << endl;
	cout << " Отсортированная матрица: " << endl;
	max = a[0][j];
	for (j = 0; j < n; j++)
	{
		p = 0;
		for (; p < n;)
		{
			max = a[p][j]; m = p;
			for (i = p; i < n; i++)
			if (a[i][j] > max)
			{
				max = a[i][j];
				m = i;
			}
			a[m][j] = a[p][j];
			a[p][j] = max;
			p++;
		}
	}

	for (i = 0; i < n; i++)
	{
		cout << endl;
		for (j = 0; j < n; j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
	system("pause");
}