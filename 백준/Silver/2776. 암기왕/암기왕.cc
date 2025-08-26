// 16:03

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	auto Input = [](vector<int>& arr, int cnt)
	{
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
		}
	};

	while (t--)
	{
		int n, m;

		cin >> n;
		vector<int> arr_n(n, 0);
		Input(arr_n, n);

		cin >> m;
		vector<int> arr_m(m, 0);
		Input(arr_m, m);

		sort(arr_n.begin(), arr_n.end());

		for (int i = 0; i < m; i++)
		{
			auto iter = lower_bound(arr_n.begin(), arr_n.end(), arr_m[i]);
			
			if (iter != arr_n.end()) 
			{
				int index = iter - arr_n.begin();
				if (arr_n[index] != arr_m[i])
				{
					cout << 0 << '\n';
				}
				else 
				{
					cout << 1 << '\n';
				}
			}
			else
			{
				cout << 0 << '\n';
			}
			
		}
	}

	return 0;
}