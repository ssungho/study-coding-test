#include <bits/stdc++.h>
using namespace std;

int m, x;
string s;
string command_list[6]
{
	"add", "remove", "check",
	"toggle", "all", "empty"
};
bitset<21> bs;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> m;

	while (m--)
	{
		cin >> s;

		if (s == command_list[0])
		{
			cin >> x;
			bs[x] = 1;
		}
		else if (s == command_list[1])
		{
			cin >> x;
			bs[x] = 0;
		}
		else if (s == command_list[2])
		{
			cin >> x;
			cout << bs[x] << '\n';
		}
		else if (s == command_list[3])
		{
			cin >> x;
			bs[x].flip();
		}
		else if (s == command_list[4])
		{
			bs.set();
		}
		else if (s == command_list[5])
		{
			bs.reset();
		}
		else
		{
			cout << "error" << '\n';
			break;
		}
	}

	return 0;
}