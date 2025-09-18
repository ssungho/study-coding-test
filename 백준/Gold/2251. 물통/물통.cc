#include <bits/stdc++.h>

using namespace std;

struct State
{
	int a, b, c;
};

int max_size[3];
bool visited[201][201];
vector<int> answer;

void move(State& curr, int from, int to, queue<State>& q)
{
	int water[3] = {curr.a, curr.b, curr.c};
	int amount = min(water[from], max_size[to] - water[to]);

	if (amount == 0)
	{
		return;
	}

	water[from] -= amount;
	water[to] += amount;

	if (!visited[water[0]][water[1]])
	{
		visited[water[0]][water[1]] = true;
		q.push({water[0], water[1], water[2]});
	}
}

int main(void)
{
	cin >> max_size[0] >> max_size[1] >> max_size[2];

	queue<State> q;
	q.push({0, 0, max_size[2]});
	visited[0][0] = true;

	while (!q.empty())
	{
		State curr = q.front();
		q.pop();

		if (curr.a == 0)
		{
			answer.push_back(curr.c);
		}

		move(curr, 0, 1, q);
		move(curr, 0, 2, q);
		move(curr, 1, 0, q);
		move(curr, 1, 2, q);
		move(curr, 2, 0, q);
		move(curr, 2, 1, q);
	}

	sort(answer.begin(), answer.end());
	for (auto i : answer)
	{
		cout << i << " ";
	}

	return 0;
}