#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int card;
		cin >> card;
		v.push_back(card);
	}

	int near_sum = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i+1; j < n - 1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				int sum = v[i] + v[j] + v[k];
				if (sum >= near_sum && sum <= m)
					near_sum = sum;
			}
		}
	}

	cout << near_sum;

	return 0;
}