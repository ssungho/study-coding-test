#include <bits/stdc++.h>
using namespace std;

int n, result, s[20][20];
bool team[20];

int calculate()
{
	int sum[2]{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && team[i] == team[j])
			{
				sum[team[i]] += s[i][j];
			}
		}
	}
	return abs(sum[0] - sum[1]);
}

void go(int here, int cnt)
{
	if (cnt > 0)
	{
		result = min(result, calculate());
	}

	for (int i = here; i < n; i++)
	{
		team[i] = true;
		go(i + 1, cnt + 1);
		team[i] = false;
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}

	result = INT_MAX;
	go(0, 0);
	cout << result << '\n';

	return 0;
}