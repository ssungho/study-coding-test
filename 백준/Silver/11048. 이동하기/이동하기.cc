#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int miro[1001][1001];
int memo_table[1001][1001];
int n, m; // 행, 열

int CountCandy(int x, int y)
{
	if (x == 1 && y == 1)
		return memo_table[1][1] = miro[1][1];

	memo_table[x][y] 
	= max({ memo_table[x - 1][y - 1] + miro[x][y],
			memo_table[x - 1][y]+ miro[x][y],
			memo_table[x][y - 1] + miro[x][y] });

	return memo_table[x][y];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int candy;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> candy;
			miro[i][j] = candy;
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			CountCandy(i, j);
		}
	}
	cout << memo_table[n][m];
	return 0;
}