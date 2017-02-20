#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 4

template<class Type>
void ShowBoard(Type* ar, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ar[i][j] << setw(2) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int title = 0;

template<class Type>
void ChessBoard(Type &ar, int tr, int tc, int dr, int dc, int n)
{
	if (n == 1) return;
	int t = ++title;
	int s = n / 2;

	if (dr < tr + s && dc < tc + s)
	{
		ChessBoard(ar, tr, tc, dr, dc, s);
	}
	else
	{
		ar[tr + s - 1][tc + s - 1] = t;
		ChessBoard(ar, tr, tc, tr + s - 1, tc + s - 1, s);
	}

	if (dr < tr + s && dc >= tc + s)
	{
		ChessBoard(ar, tr, tc + s, dr, dc, s);
	}
	else
	{
		ar[tr + s - 1][tc + s] = t;
		ChessBoard(ar, tr, tc + s, tr + s - 1, tc + s, s);
	}

	if (dr >= tr + s && dc >= tc + s)
	{
		ChessBoard(ar, tr + s, tc + s, dr, dc, s);
	}
	else
	{
		ar[tr + s][tc + s] = t;
		ChessBoard(ar, tr + s, tc + s, tr + s, tc + s, s);
	}

	if (dr >= tr + s && dc < tc + s)
	{
		ChessBoard(ar, tr + s, tc, dr, dc, s);
	}
	else
	{
		ar[tr + s][tc + s - 1] = t;
		ChessBoard(ar, tr + s, tc, tr + s, tc + s - 1, s);
	}
}

//int main()
//{
//	int Board[SIZE][SIZE] = { 0 };
//	int x, y;
//	cin >> x >> y;
//	Board[x][y] = -1;
//	ShowBoard(Board, SIZE);
//	ChessBoard(Board, 0, 0, x, y, SIZE);
//	ShowBoard(Board, SIZE);
//	return 0;
//}