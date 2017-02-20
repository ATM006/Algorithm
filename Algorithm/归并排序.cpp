#include <iostream>
#include <Windows.h>
using namespace std;


/*
第一种方法
*/

template<class Type>
void MergeCopy(Type *ds, Type *as, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		as[i] = ds[i];
	}
}

template<class Type>
void Merge(Type *ds, Type *ar, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (ar[i] <= ar[j])
			ds[k++] = ar[i++];
		else
			ds[k++] = ar[j++];
	}
	if (i > mid)
	{
		for (int p = j; p <= right; ++p)
			ds[k++] = ar[p];
	}
	else
	{
		for (int q = i; q <= mid; ++q)
			ds[k++] = ar[q];
	}
}

#if 0
template<class Type>
void MergePass(Type *ds, Type *ar, int left, int right)
{
	if (left < right)
	{
		int mid = (right - left) / 2 + left;
		MergePass(ds, ar, left, mid);
		MergePass(ds, ar, mid + 1, right);
		Merge(ds, ar, left, mid, right);			//把ds合并到ar
		MergeCopy(ds, ar, left, right);
	}
}

template<class Type>
void MergeSort(Type *ar, int n)
{
	Type *ds = new Type[n];
	MergePass(ds, ar, 0, n - 1);
	delete[]ds;
}

#endif 

template<class Type>
void MergePass(Type &ar, Type &br, int s, int n)
{
	int i = 0;
	while (i <= n - 2 * s)
	{
		Merge(br, ar, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;	//i + 2*s;
	}

	if (i + s < n)
	{
		Merge(br, ar, i, i + s - 1, n - 1);
	}
	else
	{
		for (int j = i; j <= n - 1; ++j)
		{
			br[j] = ar[j];
		}
	}

}


template<class Type>
void MergeSort(Type *ar, int n)
{
	Type *br = new Type[n];
	int s = 1;
	while (s < n)
	{
		MergePass(ar, br, s, n); //->br
		s += s;
		MergePass(br, ar, s, n); //->ar
		s += s;
	}
	delete[]br;
}


template<class Type>
void PrintArray(Type *ar, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}


//int main()
//{
//	int ar[] = { 12,32,13,45,43,36,82,29,95,54,40 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	PrintArray(ar, n);
//	MergeSort(ar, n);
//	PrintArray(ar, n);
//	system("pause");
//	return 0;
//}