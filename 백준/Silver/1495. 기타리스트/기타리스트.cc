#include <iostream>
using namespace std;

int n, s, m;
int a[51];
bool visited[51][1001];
int max_volume = -1;

void DFS(int cnt, int volume)
{
	if (cnt == n)
	{
		max_volume = max(max_volume, volume);
		return;
	}

	visited[cnt][volume] = true;

	int up = volume + a[cnt];
	if (0 <= up && up <= m && !visited[cnt + 1][up]) {
		DFS(cnt + 1, up);
	}

	int down = volume - a[cnt];
	if (0 <= down && down <= m && !visited[cnt + 1][down])
	{
		DFS(cnt + 1, down);
	}
}

int main(void)
{
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	DFS(0, s);

	cout << max_volume << '\n';

	return 0;
}