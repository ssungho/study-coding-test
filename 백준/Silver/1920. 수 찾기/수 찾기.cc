#include <bits/stdc++.h>

using namespace std;

int n, m, a[100000], target;

int BinarySearch(int x)
{
	int result = 0;
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (a[mid] == target)
		{
			result = 1;
			break;
		}

		if (a[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return result;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> target;
		cout << BinarySearch(target) << '\n';
	}

	return 0;
}