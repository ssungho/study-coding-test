#include <iostream>
using namespace std;

int apt[15][15];
int main(void)
{
	for (int i = 1; i < 15; i++)
	{
		apt[0][i] = i;
		apt[i][1] = 1;
	}

	for (int i = 1; i < 15; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			apt[i][j] = apt[i - 1][j] + apt[i][j-1];
		}
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k >> n;

		cout << apt[k][n] << endl;
	}

	return 0;
}