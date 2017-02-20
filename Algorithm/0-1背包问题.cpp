
/***
 ***********
	0-1背包问题 :给定n中物品和一背包容量c
	物品 i, wi, vi
	{x1,x2,x3,...xn}; xi{0,1} 0-1向量
	w1*x1+w2*x2+w3*x3+...+wn*xn <=c  
	v1*x1+v2*x2+v3*x3+...+vn*xn(最大)
	1.最优子结构性质
		{x1,x2,x3,...xn-1}; xi{0,1} 0-1向量
		w1*x1+w2*x2+w3*x3+...+wn-1*xn-1 <=c  
		v1*x1+v2*x2+v3*x3+...+vn-1*xn-1(最大)
	2.递归关系
		m(i,j) = m(i-1,j)  ;0<=j<wi
		m(i,j) = max{m(i-1,j),m(i-1,j-wi)+vi} ;wi<=j;
		
		m(n,j) = 0  ;0 <= j <wn
		m(n,j) = vn ;wn <= j
	3.用m[i][j]存储m(i,j)

	4.O(min{nc,2^n})
 
 ***/

#include <iostream>

#define SIZE 5

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

template<class Type>
void Knapsack(Type *w,Type *v,int i,int j,Type **m)
{
	if (w[i] > j)
	{
		m[i][j] = 0;
		return;
	}
	else
	{
		m[i][j] = v[i];
		return;
	}
	

}


int main()
{
	int n = 5;
	int c = 10;
	int W[SIZE + 1] = { 0,2,2,6,5,4 };
	int V[SIZE + 1] = { 0,6,3,5,4,6 };
	int **m = Get2Array(n,c);
	Knapsack<int>(W, V,n, c, m);

	system("pause");
	return 0;
}