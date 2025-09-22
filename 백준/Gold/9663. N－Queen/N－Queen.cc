#include <bits/stdc++.h>
using namespace std;

int n, col[15], rowcol_up[31], rowcol_down[31], answer;

void go(int y)
{
	if (y == n)
	{
		answer++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!col[i] && !rowcol_up[i + y] && !rowcol_down[i - y + (n - 1)])
		{
			col[i] = rowcol_up[i + y] = rowcol_down[i - y + (n - 1)] = 1;
			go(y + 1);
			col[i] = rowcol_up[i + y] = rowcol_down[i - y + (n - 1)] = 0;
		}
	}
}

int main(void)
{
	cin >> n;
	go(0);
	cout << answer << '\n';
	return 0;
}