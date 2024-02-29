#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// ‘ункци€ вывода
void vcout(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
// ‘ункци€ сортировки двухпутевым сли€нием
void merge(int *a, int n)
{
	int mid = n / 2; // находим середину сортируемой по-следовательности
	if (n % 2 == 1)
		mid++;
	int h = 1; // шаг
	// выдел€ем пам€ть под формируемую последовательность
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // индекс первого пути
		int j = mid; // индекс второго пути
		int k = 0;   // индекс элемента в результирующей последовательности
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // пока не дошли до конца пути заполн€ем следующий элемент формируемой последовательности меньшим из двух просматриваемых
				if (a[i] < a[j])
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i < step) // переписываем оставшиес€ элементы первого пути (если второй закончилс€ раньше)
			{
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j<n)) // пе-реписываем оставшиес€ элементы второго пути (если первый закон-чилс€ раньше)
			{
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // переходим к следующему этапу
		}
		h = h * 2;
		// ѕереносим упор€доченную последовательность (промежуточный вариант) в исходный массив
		for (i = 0; i<n; i++)
			a[i] = c[i];
	}
}
void main()
{
	setlocale(LC_ALL, "ru");
	const int r = 8;
	int a[r];
	// «аполнение массива случайными числами
	srand(time(0));
	for (int i = 0; i < r; i++)
		a[i] = rand() % 100;
	cout << "»сходный масив" << endl;
	vcout(a, r);
	merge(a, r); // вызов функции сортировки
	cout << endl;
	cout << "ќтсортированный масив" << endl;
	vcout(a, r);
	system("pause");
}
