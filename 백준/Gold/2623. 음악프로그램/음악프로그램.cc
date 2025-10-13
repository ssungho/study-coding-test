#include <bits/stdc++.h>
using namespace std;

int n, m, cnt_singer, pre_singer, cur_singer;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	vector<vector<int>> singers(n + 1);
	vector<int> in_degrees(n + 1);

	for (int i = 1; i <= m; i++)
	{
		pre_singer = -1;
		cin >> cnt_singer;

		for (int j = 0; j < cnt_singer; j++)
		{
			cin >> cur_singer;
			if (pre_singer != -1)
			{
				singers[pre_singer].push_back(cur_singer);
				in_degrees[cur_singer]++;
			}
			pre_singer = cur_singer;
		}
	}

	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= n; i++)
	{
		if (in_degrees[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int next : singers[cur])
		{
			in_degrees[next]--;
			if (in_degrees[next] == 0)
			{
				q.push(next);
			}
		}
	}

	if (result.size() != n)
	{
		cout << 0 << '\n';
	}
	else
	{
		for (int ret : result)
		{
			cout << ret << '\n';
		}
	}

	return 0;
}