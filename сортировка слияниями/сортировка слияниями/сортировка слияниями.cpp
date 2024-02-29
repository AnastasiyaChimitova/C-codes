#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// ������� ������
void vcout(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
// ������� ���������� ����������� ��������
void merge(int *a, int n)
{
	int mid = n / 2; // ������� �������� ����������� ��-����������������
	if (n % 2 == 1)
		mid++;
	int h = 1; // ���
	// �������� ������ ��� ����������� ������������������
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // ������ ������� ����
		int j = mid; // ������ ������� ����
		int k = 0;   // ������ �������� � �������������� ������������������
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // ���� �� ����� �� ����� ���� ��������� ��������� ������� ����������� ������������������ ������� �� ���� ���������������
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
			while (i < step) // ������������ ���������� �������� ������� ���� (���� ������ ���������� ������)
			{
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j<n)) // ��-���������� ���������� �������� ������� ���� (���� ������ �����-����� ������)
			{
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // ��������� � ���������� �����
		}
		h = h * 2;
		// ��������� ������������� ������������������ (������������� �������) � �������� ������
		for (i = 0; i<n; i++)
			a[i] = c[i];
	}
}
void main()
{
	setlocale(LC_ALL, "ru");
	const int r = 8;
	int a[r];
	// ���������� ������� ���������� �������
	srand(time(0));
	for (int i = 0; i < r; i++)
		a[i] = rand() % 100;
	cout << "�������� �����" << endl;
	vcout(a, r);
	merge(a, r); // ����� ������� ����������
	cout << endl;
	cout << "��������������� �����" << endl;
	vcout(a, r);
	system("pause");
}
