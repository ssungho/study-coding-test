#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	set<string> s;

	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		s.emplace(temp);
	}

	int count = 0;
	for (int i = 0; i < m; ++i)
	{
		string temp;
		cin >> temp;
		if (s.end() != s.find(temp))
			count++;
	}

	cout << count;

	return 0;
}