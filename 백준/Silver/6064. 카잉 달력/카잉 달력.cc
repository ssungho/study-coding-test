#include<iostream>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int ny = 0, k = 0, cnt = 0;
		while (true)
		{
			k = (M * cnt) + x;
			ny = k % N;
			if (ny == 0)
				ny = N;
			if (ny == y)
			{
				cout << k << '\n';
				break;
			}
			else
				cnt++;
			if (k > M * N)
			{
				cout << -1 << '\n';
				break;
			}
		}
	}
	return 0;
}