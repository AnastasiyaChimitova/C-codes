#include <iostream>
#include <stdlib.h>
#include <time.h>
#define n 8
using namespace std;
// ������� ������
void vcout(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
// ������� ���������� ���������� ��������
void merge(int *a, int l, int r)
{
	if (l == r) return; // ������� ����������
	int mid = (l + r) / 2; // ���������� �������� ���������-���������
	// � ���������� �������� ������� ���������� ��� ������ ��-������
	merge(a, l, mid);
	merge(a, mid + 1, r);
	int i = l;  // ������ ������� ����
	int j = mid + 1; // ������ ������� ����
	int *c = (int*)malloc(r * sizeof(int)); // �������������� ������
	for (int k = 0; k < r - l + 1; k++) // ��� ���� ��������� ��������������� �������
	{
		// ���������� � ����������� ������������������ ����-��� �� ��������� ���� �����
		// ��� ������� ������� ���� ���� j > r
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
	// ������������ �������������� ������������������ � �����-��� ������
	for (int k = 0; k < r - l + 1; k++)
		a[l + k] = c[k];
}
void main()
{
	setlocale(LC_ALL, "ru");
	int a[n];
	// ��������� �������� �������
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
	cout << "�������� ������" << endl;
	vcout(a, n);
	merge(a, 0, n - 1); // �������� ������� ����������
	cout << endl;
	cout << "��������������� ������" << endl;
	vcout(a, n);
	system("pause");
}
