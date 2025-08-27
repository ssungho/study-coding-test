#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> temp;
vector<bool> visited;

void DFS(int index)
{
	if (temp.size() == n)
	{
		for (auto i : temp)
		{
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			temp.push_back(i + 1);
			DFS(i + 1);
			temp.pop_back();
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	visited.resize(n, false);

	DFS(0);

	return 0;
}