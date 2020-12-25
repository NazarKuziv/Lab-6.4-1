// Lab_06_4.cpp
// < Кузів Назар >
// Лабораторна робота № 6.4-1
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 6


#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const  int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);

}

void Cout(int* a, const int size)
{
	cout << "a[] = {";

	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << a[i];
	}

	cout << "  }" << endl;
	cout  << endl;
}

void CoutMin(int min)
{
	cout << "1.1) Min = " << min<<endl;
	
}

void CoutSum(int Sum)
{
	cout << "1.2) Sum = " << Sum << endl;

}

int SearchMin(int* a, const int size)
{
	int min =a[0];

	for (int i = 1; i < size; i++)
		if (a[i]<min)
		{
			min = a[i];
		}
	return min;
}

int SearchFirst(int* a, const int size)
{
	int f = -1;

	for (int i = 0; i < size; i++)
	{
		if (a[i] > 0)

		f = i;
		break;
	}

		return f;
	
}

int SearchLast(int* a, const int size,const int First)
{	
	int f = -1;

	for (int i = size; i >= 0; i--)
		if (a[i] > 0)
		{
			f = i;
			break;
		}

	if (f != First)

		return f;
	else
		return -1;
}

int Sum(int* a,int First, int Last )
{
	int S = 0;

	for (int i = First+1; i < Last; i++)
	{
		S += a[i];
	}

	return S;
}

void Sort(int* a, const int size) 
{	
	int zero = -1;

	for (int i = 0; i < size - 1; i++) 
	{
		if (a[i] == 0)
		{
			zero = i;
			break;
		}
	}

	if (zero == -1)
	{

		cout << "There are no zeros in this array" << endl;
		cout << endl;
	}
	else
	{
		int z;

		for (int i = 0; i <size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (a[j] == 0)
				{
					z = a[j];
					a[j] = a[i];
					a[i] = z;
				}
			}
		}

	}

}

int main()
{
	srand((unsigned)time(NULL));


	int Low, High, n, Min;

	cout << "Array size ="; cin >> n;

	int* a = new int[n];

	cout << "Low ="; cin >> Low;
	cout << "High ="; cin >> High;
	cout << endl;

	Create(a, n, Low, High);
	Cout(a, n);

	Min = SearchMin(a, n);
	CoutMin(Min);
	cout << endl;
	
	const int First = SearchFirst(a, n);
	const int Last = SearchLast(a, n, First);
	cout << endl;

	cout << "First a["<< First <<"] = " <<a[First]<<endl;
	cout << "Last a[" << Last << "] = " << a[Last] << endl;

	if(First == -1 || Last == -1)

		cout << "Error"<< endl;

	else
	{
		int S = Sum(a, First, Last);
		CoutSum(S);
	}

	cout << endl;
	Sort(a, n);
	Cout(a, n);
	
	return 0;
}

