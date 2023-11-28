#include <iostream>
#include <algorithm>
using namespace std;

int pos[501][501];
long long memo[257];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	long long b;
	cin >> n >> m >> b;

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int height;
			cin >> height;
			pos[j][i] = height;
		}
	}

	int make = 1;
	int remove = 2;
	long long result_time = 2147486347;
	int result_height = 0;

	for (int h = 0; h < 257; h++)
	{
		long long have = b;
		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				long long height = pos[j][i];
				long long apply = 0;

				if (h > height)
				{
					apply = make * (h - height);
					have -= (h - height);
				}
				else
				{
					apply = remove * (height - h);
					have += (height - h);
				}

				memo[h] += apply;
			}
		}

		if (have < 0)
			memo[h] = 2147486347;

		if (memo[h] <= result_time)
		{
			result_time = memo[h];
			result_height = h;
		}
	}

	cout << result_time << " " << result_height;

	return 0;
}