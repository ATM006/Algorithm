

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
using namespace std;


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
		if (i < j) ar[i++] = ar[j];
		while (i < j && ar[i] <= temp) ++i;
		if (i <j) ar[j--] = ar[i];
	}
	ar[i] = temp;
	return i;
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


template<class Type>
Type SelectK(Type *ar, int left, int right, int k)
{
	if (left == right && k == 1)
		return ar[left];
	int pos = Partition(ar, left, right);
	int i = pos - left + 1;
	if (k <= i) return SelectK(ar, left, pos, k);
	else return SelectK(ar, pos + 1, right, k - i);
}
template<class Type>
Type SelectKMin(Type *ar, int n, int k)
{
	return SelectK(ar, 0, n - 1, k);
}

/*
***最近点问题
*/
#define MAXINT 0x7fffffff
template<class Type>
Type Min(Type a, Type b)
{
	return a < b ? a : b;
}

template<class Type>
Type Min(Type a, Type b, Type c)
{
	return Min(Min(a, b), c);
}

template<class Type>
Type Min(Type *ar, int n)
{
	Type min = ar[0];
	for (int i = 1; i < n; ++i)
	{
		if (ar[i] < min)
			min = ar[i];
	}
	return min;
}

template<class Type>
Type Max(Type *ar, int n)
{
	Type max = ar[0];
	for (int i = 1; i < n; ++i)
	{
		if (ar[i] > max)
			max = ar[i];
	}
	return max;
}

template<class Type>
Type CpairPart(Type *ar, int n)
{
	Type d = MAXINT;
	if (n <= 1)
	{
		return d;
	}           
	int k = n / 2;
	SelectKMin(ar, n, k);
	int d1 = CpairPart(ar,k);
	int d2 = CpairPart(ar+k, n - k);
	int smax = Max(ar, k);
	int smin = Min(ar + k, n - k); 
	d = Min(d1, d2,smin - smax);
	
	return d;
}


template<class Type>
Type Cpair(Type *ar, int n)
{
	if (n < 1)exit(0);
	return CpairPart(ar, n);
}


//int main()
//{
//	int ar[] = {101, 56,78,93,100,34,45,86,13,67 };
//	int len = sizeof(ar) / sizeof(ar[0]);
//	PrintArr(ar, len);
//	cout << Cpair(ar, len) << endl;;
//	system("pause");
//}



