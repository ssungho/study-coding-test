#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << 1 << '\n';
			continue;
		}

		long long num = 1;
		long long cnt = 1;
		while (true)
		{
			if (num == 0)
			{
				cout << cnt << '\n';
				break;
			}
			else
			{
				num = (num * 10 + 1) % n;
				cnt++;
			}
		}
	}

	return 0;
}