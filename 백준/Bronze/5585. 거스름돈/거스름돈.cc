#include <bits/stdc++.h>
using namespace std;

int n, result;
vector<int> coins{500, 100, 50, 10, 5, 1};

int main(void)
{
	cin >> n;
	n = 1000 - n;
	
	for (auto coin : coins) 
	{
		while (n - coin >= 0) 
		{
			n -= coin;
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}