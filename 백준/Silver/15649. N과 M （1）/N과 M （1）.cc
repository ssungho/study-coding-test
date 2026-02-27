#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[9];
vector<int> v;

void go(int here, int cnt)
{
	if (cnt == m)
	{
		for (auto i : v)
		{
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			v.push_back(i);
			go(i + 1, cnt + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main(void)
{
	cin >> n >> m;
	go(1, 0);
	return 0;
}