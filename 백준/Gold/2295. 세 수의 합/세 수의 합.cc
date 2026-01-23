#include <bits/stdc++.h>
using namespace std;

int n, target, result = -1;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	vector<int> nums, sums;
	nums.resize(n);
	sums.reserve(n * n);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			sums.push_back(nums[i] + nums[j]);
		}
	}
	sort(sums.begin(), sums.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			target = nums[i] - nums[j];
			if (binary_search(sums.begin(), sums.end(), target))
			{
				result = nums[i];
				break;
			}
		}

		if (result != -1)
		{
			cout << result << '\n';
			break;
		}
	}

	return 0;
}