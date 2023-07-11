#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<long> nums;

	for (int i = 0; i < N; i++)
	{
		long num;
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		long target = nums[i];
		int start = 0;
		int end = N - 1;

		while (start < end)
		{
			if (nums[start] + nums[end] == target)
			{
				if (start != i && end != i)
				{
					cnt++;
					break;
				}
				else if (start == i)
					start++;
				else if (end == i)
					end--;
			}
			else if (nums[start] + nums[end] < target)
				start++;
			else if (nums[start] + nums[end] > target)
				end--;
		}
	}
	cout << cnt;

	return 0;
}