#include <iostream>
#include <stdlib.h>
#include <time.h>
#define n 8
using namespace std;
// Функция вывода
void vcout(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
// Функция сортировки нисходящим слиянием
void merge(int *a, int l, int r)
{
	if (l == r) return; // границы сомкнулись
	int mid = (l + r) / 2; // определяем середину последова-тельности
	// и рекурсивно вызываем функцию сортировки для каждой по-ловины
	merge(a, l, mid);
	merge(a, mid + 1, r);
	int i = l;  // начало первого пути
	int j = mid + 1; // начало второго пути
	int *c = (int*)malloc(r * sizeof(int)); // дополнительный массив
	for (int k = 0; k < r - l + 1; k++) // для всех элементов дополнительного массива
	{
		// записываем в формируемую последовательность мень-ший из элементов двух путей
		// или остаток первого пути если j > r
		if ((j > r) || ((i <= mid) && (a[i] < a[j])))
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = a[j];
			j++;
		}
	}
	// переписываем сформированную последовательность в исход-ный массив
	for (int k = 0; k < r - l + 1; k++)
		a[l + k] = c[k];
}
void main()
{
	setlocale(LC_ALL, "ru");
	int a[n];
	// Заполняем элементы массива
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
	cout << "Исходный массив" << endl;
	vcout(a, n);
	merge(a, 0, n - 1); // вызываем функцию сортировки
	cout << endl;
	cout << "Отсортированный массив" << endl;
	vcout(a, n);
	system("pause");
}
