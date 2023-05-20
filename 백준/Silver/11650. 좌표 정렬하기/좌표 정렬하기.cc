#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main(void)
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << v.at(i).first << " " << v.at(i).second << '\n';
	}

	return 0;
}