#include <bits/stdc++.h>
using namespace std;

int n, result, s[20][20];
bool team[20];

int calculate()
{
	int sum[2]{};
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i != j && team[i] == team[j])
			{
				sum[team[i]] += s[i][j] + s[j][i];
			}
		}
	}
	return abs(sum[0] - sum[1]);
}

void go(int here, int cnt)
{
	if (cnt > 0 && cnt < n)
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
	team[0] = true;
	go(1, 1);
	cout << result << '\n';

	return 0;
}