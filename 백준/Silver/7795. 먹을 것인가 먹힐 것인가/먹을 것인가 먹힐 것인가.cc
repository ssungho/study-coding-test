#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search(vector<int>& v, int target)
{
	int index = -1;
	int left = 0;
	int right = v.size() - 1;

	while (left <= right)
	{
		int index_mid = (left + right) / 2;
		int value_mid = v[index_mid];

		if (value_mid < target)
		{
			index = index_mid;
			left = index_mid + 1;
		}
		else
		{
			right = index_mid - 1;
		}
	}

	return index;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int a, b;
		cin >> a >> b;

		vector<int> arr_a(a, 0), arr_b(b, 0);

		for (int i = 0; i < a; i++)
		{
			cin >> arr_a[i];
		}

		for (int i = 0; i < b; i++)
		{
			cin >> arr_b[i];
		}

		sort(arr_b.begin(), arr_b.end());

		int count = 0;
		for (int i = 0; i < a; i++)
		{
			int size_a = arr_a[i];
			int index = Search(arr_b, size_a);
			if (-1 != index)
			{
				count += (index + 1);
			}
		}

		cout << count << '\n';
	}

	return 0;
}