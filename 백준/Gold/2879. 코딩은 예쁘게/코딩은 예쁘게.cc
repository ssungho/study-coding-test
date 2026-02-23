#include <bits/stdc++.h>
using namespace std;

int n, result, arr[1001];
pair<int, int> gap[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> gap[i].second;
		gap[i].second -= arr[i];

		if (gap[i].second > 0)
		{
			gap[i].first = 1;
		}
		else if (gap[i].second < 0)
		{
			gap[i].first = -1;
		}
	}

	int start = 1;
	
	while (true)
	{
		while (start <= n && gap[start].first == 0)
		{
			start++;
		}

		if (start > n)
		{
			break;
		}

		int flag = gap[start].first;
		int cnt = abs(gap[start].second);
		int here = start;

		while (true)
		{
			if (flag == gap[here].first && here <= n)
			{
				cnt = min(cnt, abs(gap[here].second));
				here++;
			}
			else
			{
				for (int i = start; i < here; i++)
				{
					flag == 1 ? gap[i].second -= cnt : gap[i].second += cnt;
					if (gap[i].second == 0)
					{
						gap[i].first = 0;
					}
				}

				result += cnt;
				break;
			}
		}
	}

	cout << result << '\n';

	return 0;
}