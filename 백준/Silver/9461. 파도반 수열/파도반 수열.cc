#include <iostream>
using namespace std;

long long memo[101];
long long FindP(int x)
{
	memo[1] = 1, memo[2] = 1, memo[3] = 1;

	for (int i = 4; i < x + 1; i++)
	{
		if(memo[i] == 0)
			memo[i] = memo[i - 2] + memo[i - 3];
	}

	return memo[x];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << FindP(N) << '\n';
	}
	return 0;
}