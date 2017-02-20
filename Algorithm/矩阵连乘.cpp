/********************************
***	动态规划
1.找出最优子结构性质,刻画其结构特征
2.递归定义最优值
3.自底向上计算最优值
4.根据计算的最优值得到的信息,构造一个最优解
********************************/

#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;
/*** 1 矩阵连乘 *******************/
int num = 0;

int * GetArray(int n)
{
	int *s = (int*)malloc(sizeof(int)*n);
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(int)*n);
	return s;
}

void Del_Array(int *p)
{
	free(p);
}

int ** Get2Array(int n, int m)
{
	int **s = (int**)malloc(sizeof(int*)*n); //int **s = (int**)malloc(sizeof(int)*n);错误
	if (NULL == s) exit(1);
	for (int i = 0; i<n; ++i)
	{
		s[i] = (int*)malloc(sizeof(int)*m);
		memset(s[i], 0, sizeof(int)*m);
	}
	return s;
}

void Del_2Array(int **p, int n)
{
	for (int i = 0; i<n; ++i)
	{
		free(p[i]);
	}
	free(p);
}

// a 3*4   b 4*2 
void MatrixMultiply(int **a, int **b, int **c, int ar, int ac, int br, int bc)
{// O(ar*br*bc);
	if (ac != br) exit(1);
	for (int i = 0; i<ar; ++i)
	{
		for (int j = 0; j<bc; ++j)
		{
			int tmp = 0;
			for (int k = 0; k<ac; ++k)
			{
				tmp += a[i][k] * b[k][j];
			}
			c[i][j] = tmp;
		}
	}
}

#define MSIZE 6
int m[MSIZE + 1][MSIZE + 1] = { 0 };
int s[MSIZE + 1][MSIZE + 1] = { 0 };

template<class Type>
Type MatrixChain(Type *p, int i, int j)
{
	num += 1;
	if (i == j)	return 0;
	if (m[i][j] != 0)
	{
		return m[i][j];
	}

	//m[i][j] = MatrixChain(p, i, i) + MatrixChain(p, i + 1, j) + p[i - 1] * p[i] * p[j];
	m[i][j] = 0 + MatrixChain(p, i + 1, j) + p[i - 1] * p[i] * p[j];
	s[i][j] = i;
	for (int k = i + 1; k < j; ++k)
	{
		Type t = MatrixChain(p, i, k) + MatrixChain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
		if (t < m[i][j])
		{
			m[i][j] = t;
			s[i][j] = k;
		}
	}
	return m[i][j];
}

template<class Type>
Type MatrixChain2(Type *p, int n)
{
	if (n == 1) return 0;
	//for (int i = 1; i <= n; i++)m[i][i] = 0;
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}

	}



}

void Print(int a[][MSIZE + 1], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << setw(7) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Traceback(int i, int j, int s[][MSIZE + 1])
{

	if (i == j)return;

	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);


	cout << "A" << i << "->" << "A" << s[i][j] + 1 << endl;

}

//int main(int argc, char const *argv[])
//{
//	int p[MSIZE + 1] = { 30,35,15,5,10,20,25 };
//	
//	int  minx = MatrixChain2(p,MSIZE);
//
//	Print(m, MSIZE);
//	Print(s, MSIZE);
//	/*
//	int  minx = MatrixChain(p, 1, MSIZE);
//	cout << minx << endl;
//	
//	Print(m, MSIZE);
//	Print(s, MSIZE);
//
//	Traceback(1, MSIZE, s);
//	cout << num << endl;
//	*/
//	system("pause");
//	return 0;
//}

