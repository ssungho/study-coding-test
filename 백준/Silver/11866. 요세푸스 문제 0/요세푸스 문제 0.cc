#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	cout << '<';

	int cnt = 0;
	while (v.size() > 0)
	{
		cnt++;
		int temp = v.front();
		v.erase(v.begin());
		if (cnt % k != 0)
		{
			v.push_back(temp);
		}
		else
		{
			if (v.size() == 0)
				cout << temp;
			else
				cout << temp << ',' << " ";
		}
	}
	cout << '>';

	return 0;
}