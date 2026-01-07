#include <bits/stdc++.h>

using namespace std;

int n, graph[101];
bool visited[101];
vector<int> temp;
set<int> answer;

void go(int current, vector<int>& v)
{
	visited[current] = true;
	v.push_back(current);

	if (visited[graph[current]] == false)
	{
		go(graph[current], v);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> graph[i];
	}

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		temp.clear();

		go(i, temp);
		if (graph[temp.back()] == i)
		{
			for (int j : temp)
			{
				answer.insert(j);
			}
		}
	}

	cout << answer.size() << '\n';
	for (int i : answer)
	{
		cout << i << '\n';
	}

	return 0;
}