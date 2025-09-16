#include <bits/stdc++.h>

using namespace std;

int n, low, high, sum, result;

int main(void)
{
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	high = n - 1;
	result = INT_MAX;

	while (low < high)
	{
		sum = v[low] + v[high];

		if (abs(result) > abs(sum))
		{
			result = sum;
		}

		if (sum < 0)
		{
			low++;
		}
		else
		{
			high--;
		}
	}

	cout << result << '\n';

	return 0;
}