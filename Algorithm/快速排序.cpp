
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
using namespace std;

/***
***********随机划分*******************
***/
template<class Type>
void Swap(Type &a, Type &b)
{
	Type tmp = a;
	a = b;
	b = tmp;
}
template<class Type>
int RandPartition(Type *ar, int left, int right)
{
	srand(time(0));
	int pos = (rand() % (right - left + 1)) + left;
	Swap(ar[left], ar[right]);
	return Partition(ar, left, right);
}

/***
***********普通划分*******************
***/
template<class Type>
int Partition(Type *ar, int left, int right)
{

	int i = left;
	int j = right;
	Type temp = ar[i];

	while (i < j)
	{
		while (i < j && ar[j] >= temp) --j;
		if (i < j) ar[i] = ar[j];
		while (i < j && ar[i] <= temp) ++i;
		if (i <j) ar[j] = ar[i];
	}
	ar[i] = temp;
	return i;
}

template<class Type>
void Quik(Type *ar, int left, int right)
{
	if (left < right)
	{
		//int index = Partition(ar, left, right);
		int index = RandPartition(ar, left, right);
		Quik(ar, left, index - 1);
		Quik(ar, index + 1, right);
	}
}

template<class Type>
void QuickSort(Type *ar, int n)
{
	Quik(ar, 0, n - 1);
}

template<class Type>
void PrintArr(Type *ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}



//int main()
//{
//
//	int ar[] = { 54,23 ,78 ,84 ,40,30 };//,18 };
//	int len = sizeof(ar) / sizeof(ar[0]);
//	PrintArr(ar, len);
//
//	QuickSort(ar, len);
//	PrintArr(ar, len);
//
//
//	//return 0;
//	system("pause");
//}

