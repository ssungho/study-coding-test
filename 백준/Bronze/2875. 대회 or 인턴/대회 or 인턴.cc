#include <iostream>

using namespace std;

int n, m, k;

int main(void)
{
	cin >> n >> m >> k;

	int cnt_team = 0;

	if (n >= 2 && m >= 1)
	{
		while (true)
		{
			if (k == 0)
			{
				cnt_team = min(n / 2, m);
				break;
			}

			if (n >= 2 * m)
			{
				n--;
			}
			else
			{
				m--;
			}

			k--;
		}
	}

	cout << max(0, cnt_team) << '\n';

	return 0;
}