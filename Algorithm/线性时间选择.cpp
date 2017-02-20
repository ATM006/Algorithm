
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
	srand(time(NULL));
	int pos = (rand() % (right - left + 1)) + left;
	//int pos = (rand() % (right - left)) + left+1;
	//cout << pos << " ";
	Swap(ar[left], ar[pos]);  //XXX
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
	Type temp = ar[left];

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

/****
**** SelectK*********
***/
template<class Type>
Type SelectK(Type *ar, int left, int right, int k)
{
	if (left == right && k == 1)
		return ar[left];
	int ret = RandPartition(ar, left, right);
	int i = ret - left + 1;
	if (k <= i)
	{
		return SelectK(ar, left, ret, k);
	}
	else
	{
		return SelectK(ar, ret + 1, right, k - i);
	}
}



template<class Type>
Type SelectKMin(Type* ar, int n, int k)
{
	if (k < 1)exit(0);
	return SelectK(ar, 0, n - 1, k);
}


//int main()
//{
//
//	int ar[] = { 54,23 ,78 ,84 ,40,30 };//,18 };
//	int len = sizeof(ar) / sizeof(ar[0]);
//	PrintArr(ar, len);
//
//	//cout << SelectKMin(ar, len, 1) << endl;
//	//cout << SelectKMin(ar, len, 4) << endl;
//	for (int i = 1; i < len; ++i)
//	{
//		cout << i << " " << SelectKMin(ar, len, i) << endl;
//	}
//
//	//return 0;
//	system("pause");
//}

