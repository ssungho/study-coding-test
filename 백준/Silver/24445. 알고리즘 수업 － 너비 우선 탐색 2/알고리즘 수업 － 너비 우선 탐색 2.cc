#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> graph[100001];
int visited[100001];

void BFS(int start_node)
{
	int seq = 1;
	queue<int> q;

	q.push(start_node);
	visited[start_node] = seq;
	seq++;

	while (!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			// 방문하지 않았다면,
			if (visited[graph[cur_node][i]] == 0)
			{
				visited[graph[cur_node][i]] = seq;
				seq++;
				q.push(graph[cur_node][i]);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	int node1, node2;
	for (int i = 0; i < M; i++)
	{
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	for (int i = 1; i < N + 1; i++)
		sort(graph[i].begin(), graph[i].end(), greater<int>());

	BFS(R);
	for (int i = 1; i < N + 1; i++)
		cout << visited[i] << '\n';

	return 0;
}