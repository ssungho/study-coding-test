#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int sums[100001]{1};

	for (int i = 1; i < N + 1; i++)
	{
		int temp;
		cin >> temp;
	
		sums[i] = sums[i-1] + temp;
	}

	for (int k = 0; k < M; k++)
	{
		int i, j;
		cin >> i >> j;

		int temp;
		temp = sums[j] - sums[i - 1];

		cout << temp << '\n';
	}

	return 0;
}