#include <bits/stdc++.h>
using namespace std;

int n, m;
string dp[101][101];

using ri = std::reverse_iterator<std::string::iterator>;
bool add_str(ri iter1, ri end_iter1, bool add, std::string &str)
{
	while (iter1 != end_iter1)
	{
		int num = (*iter1 - '0');
		if (add) num++;

		if (num > 9) add = true;
		else add = false;

		str.push_back(num % 10 + '0');
		iter1++;
	}

	return add;
}

int main(void)
{
	cin >> n >> m;

	dp[0][0] = "1";
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = "1";
		for (int j = 1; j <= i; j++)
		{
			auto iter1 = dp[i - 1][j].rbegin();
			auto iter2 = dp[i - 1][j - 1].rbegin();
			auto end_iter1 = dp[i - 1][j].rend();
			auto end_iter2 = dp[i - 1][j - 1].rend();

			string str = "";
			bool add = false;

			while (iter1 != end_iter1 && iter2 != end_iter2)
			{
				int num = (*iter1 - '0') + (*iter2 - '0');
				if (add) num++;

				if (num > 9) add = true;
				else add = false;

				str.push_back(num % 10 + '0');
				iter1++;
				iter2++;
			}

			add = add_str(iter1, end_iter1, add, str);
			add = add_str(iter2, end_iter2, add, str);

			if (add)
			{
				str.push_back('1');
			}

			reverse(str.begin(), str.end());
			dp[i][j] = move(str);
		}
	}

	cout << dp[n][m] << '\n';

	return 0;
}