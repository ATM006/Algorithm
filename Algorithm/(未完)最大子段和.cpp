#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>

template<class Type>
int MaxSum(Type *a, int n, int &besti, int &bestj)  //O(n^3)
{
	int sum = 0;
	for (int i = 0; i<n; i++)
		for (int j = i; j < n; j++)
		{
			int thissum = 0;
			for (int k = i; k <= j; k++)
				thissum += a[k];
			if (thissum > sum)
			{
				sum = thissum;
				besti = i;
				bestj = j;
			}
		}
	return sum;
}

template<class Type>
int MaxSum2(Type *a, int n, int &besti, int &bestj)  //O(n^2)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int thissum = 0;
		for (int j = i; j < n; j++)
		{
			//for (int k = i; k <= j; k++)
			thissum += a[j];
			if (thissum > sum)
			{
				sum = thissum;
				besti = i;
				bestj = j;
			}
		}
	}
	return sum;
}
template<class Type>
int MaxSubSum(Type *a, int left, int right)
{

}

template<class Type>
int MaxSum(Type *a, int n)  //O(n^2)
{
	return MaxSubSum(a, 0, n - 1);
}



//int main()
//{
//	int index_i = 0;
//	int index_j = 0;
//	int ar[] = { -2,11,-4,13,-5,-2 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	int sum = MaxSum<int>(ar, n, index_i, index_j);
//	std::cout <<index_i<<"-->"<<index_j<< sum << std::endl;
//	system("pause");
//	return 0;
//}
//
