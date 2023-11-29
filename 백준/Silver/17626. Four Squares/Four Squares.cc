#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int memo[50001];

int main(void)
{
	int n;
	cin >> n;

	memo[1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		int count = 3;

		for (int j = 1; (int)pow(j, 2) < i + 1; j++)
		{
			int temp = i - (int)pow(j, 2);
			count = min(count, memo[temp]);
		}

		memo[i] = count + 1;
	}

	cout << memo[n];

	return 0;
}