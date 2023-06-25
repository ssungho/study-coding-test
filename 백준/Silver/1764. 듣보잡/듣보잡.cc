#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> list;
	vector<string> v;

	int N, M;
	cin >> N >> M;

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		list.insert(make_pair(temp, 0));
		v.push_back(temp);
	}
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;

		if (list.find(temp) != list.end())
		{
			list[temp]++;
			cnt++;
		}
		else
		{
			list.insert(make_pair(temp, 0));
			v.push_back(temp);
		}

	}
	sort(v.begin(), v.end());

	cout << cnt << '\n';

	for (int i = 0; i < v.size(); i++)
	{
		string temp = v[i];
		if (list[temp] > 0)
			cout << temp << '\n';
	}

	return 0;
}