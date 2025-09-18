#include <bits/stdc++.h>

using namespace std;

struct State
{
	int a, b, c;
};

int max_size[3];
bool visited[201][201][201];
bool check[201];
vector<int> answer;

int main(void)
{
	cin >> max_size[0] >> max_size[1] >> max_size[2];

	queue<State> q;
	q.push({0, 0, max_size[2]});
	visited[0][0][max_size[2]] = true;

	while (!q.empty())
	{
		State curr = q.front();
		q.pop();

		if (curr.a == 0)
		{
			answer.push_back(curr.c);
		}

		// a -> b
		int amount = min(curr.a, max_size[1] - curr.b);
		State next = {curr.a - amount, curr.b + amount, curr.c};
		if (!visited[next.a][next.b][next.c])
		{
			visited[next.a][next.b][next.c] = true;
			q.push(next);
		}

		// a -> c
		amount = min(curr.a, max_size[2] - curr.c);
		next = {curr.a - amount, curr.b, curr.c + amount};
		if (!visited[next.a][next.b][next.c])
		{
			visited[next.a][next.b][next.c] = true;
			q.push(next);
		}

		// b -> c
		amount = min(curr.b, max_size[2] - curr.c);
		next = {curr.a, curr.b - amount, curr.c + amount};
		if (!visited[next.a][next.b][next.c])
		{
			visited[next.a][next.b][next.c] = true;
			q.push(next);
		}

		// b -> a
		amount = min(curr.b, max_size[0] - curr.a);
		next = {curr.a + amount, curr.b - amount, curr.c};
		if (!visited[next.a][next.b][next.c])
		{
			visited[next.a][next.b][next.c] = true;
			q.push(next);
		}

		// c -> a
		amount = min(curr.c, max_size[0] - curr.a);
		next = {curr.a + amount, curr.b, curr.c - amount};
		if (!visited[next.a][next.b][next.c])
		{
			visited[next.a][next.b][next.c] = true;
			q.push(next);
		}

		// c -> b
		amount = min(curr.c, max_size[1] - curr.b);
		next = {curr.a, curr.b + amount, curr.c - amount};
		if (!visited[next.a][next.b][next.c])
		{
			visited[next.a][next.b][next.c] = true;
			q.push(next);
		}
	}

	sort(answer.begin(), answer.end());
	for (auto i : answer)
	{
		cout << i << " ";
	}

	return 0;
}