#include <iostream>
using namespace std;

long long memo[101];
long long FindP(int x)
{
	memo[1] = 1, memo[2] = 1, memo[3] = 1;
	memo[4] = 2, memo[5] = 2;

	for (int i = 6; i < x + 1; i++)
	{
		if(memo[i] == 0)
			memo[i] = memo[i - 5] + memo[i - 1];
	}

	return memo[x];
}

int main(void)
{
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << FindP(N) << '\n';
	}
	return 0;
}