#include <iostream>
#include <algorithm>
using namespace std;

int memo[1000001];
int func(int x)
{
	memo[1] = 0;
	for (int i = 2; i < x + 1; i++)
	{
		memo[i] = memo[i - 1] + 1;

		if (i % 3 == 0)
			memo[i] = min(memo[i], memo[i / 3] + 1);
		if (i % 2 == 0)
			memo[i] = min(memo[i], memo[i / 2] + 1);
	}
	return memo[x];
}
int main(void)
{
	int N;
	cin >> N;
	cout << func(N);
	return 0;
}