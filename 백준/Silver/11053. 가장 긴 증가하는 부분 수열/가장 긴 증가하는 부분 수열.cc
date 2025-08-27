#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> lis;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		auto iter = lower_bound(lis.begin(), lis.end(), num);
		
		if (iter == lis.end())
		{
			lis.push_back(num);
		}
		else
		{
			*iter = num;
		}
	}

	cout << lis.size() << '\n';

	return 0;
}