#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	vector<pair<int, int>> v;
	int nums[50];

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
		nums[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		pair<int, int> temp = v.at(i);
		for (int j = 0; j < n; j++)
		{
			pair<int, int> temp2 = v.at(j);
			if ((temp.first < temp2.first) && (temp.second < temp2.second))
				nums[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
	
	return 0;
}