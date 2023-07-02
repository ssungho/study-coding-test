#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
int visited_seq[100001];
bool visited[100001];

int seq = 1;

void DFS(int node)
{
	visited[node] = true;
	visited_seq[node] = seq;
	seq++;
	for (int i = 0; i < graph[node].size(); i++)
		if (!visited[graph[node][i]])
			DFS(graph[node][i]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, R;
	cin >> N >> M >> R;
	
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	for (int i = 0; i < N; i++)
		sort(graph[i].begin(), graph[i].end());
	
	DFS(R);

	for (int i = 1; i < N + 1; i++)
	{
		cout << visited_seq[i] << '\n';
	}
	return 0;
}