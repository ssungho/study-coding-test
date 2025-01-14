#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	set<string> s;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		s.emplace(temp);
	}

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;
		if (s.end() != s.find(temp))
			count++;
	}

	cout << count;

	return 0;
}