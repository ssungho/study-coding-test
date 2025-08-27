#include <iostream>
#include <vector>

using namespace std;

int n, s, cnt;
vector<int> v;

void DFS(int index, int sum)
{
	if (sum == s && index > 0)
	{
		cnt++;
	}

	for (int i = index; i < n; i++)
	{
		DFS(i + 1, sum + v[i]);
	}
}

int main(void)
{
	cin >> n >> s;

	v.resize(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	DFS(0, 0);

	cout << cnt << '\n';

	return 0;
}