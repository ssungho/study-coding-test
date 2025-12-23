#include <bits/stdc++.h>
using namespace std;

string strs[3];
int lens[3], lcs[101][101][101];
int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		cin >> strs[i];
		lens[i] = (int)strs[i].size();
	}

	for (int i = 1; i <= lens[0]; i++)
	{
		for (int j = 1; j <= lens[1]; j++)
		{
			for (int k = 1; k <= lens[2]; k++)
			{
				int pos_i = i - 1;
				int pos_j = j - 1;
				int pos_k = k - 1;

				if (strs[0][pos_i] == strs[1][pos_j] && strs[0][pos_i] == strs[2][pos_k])
				{
					lcs[i][j][k] = lcs[pos_i][pos_j][pos_k] + 1;
				}
				else
				{
					lcs[i][j][k] = max({lcs[pos_i][j][k], lcs[i][pos_j][k], lcs[i][j][pos_k]});
				}
			}
		}
	}

	cout << lcs[lens[0]][lens[1]][lens[2]] << '\n';

	return 0;
}