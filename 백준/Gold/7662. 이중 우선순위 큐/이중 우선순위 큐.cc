#include <bits/stdc++.h>
using namespace std;

int t, k, num;
char op;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		priority_queue<int, vector<int>, greater<int>> pq_asc;
		priority_queue<int> pq_desc;
		unordered_map<int, int> visited;

		cin >> k;
		while (k--)
		{
			cin >> op >> num;
			if (op == 'I')
			{
				pq_asc.push(num);
				pq_desc.push(num);
				visited[num]++;
			}
			else if (op == 'D')
			{
				if (num == -1 && pq_asc.size())
				{
					visited[pq_asc.top()]--;
					pq_asc.pop();
				}
				if (num == 1 && pq_desc.size())
				{
					visited[pq_desc.top()]--;
					pq_desc.pop();
				}
			}

			while (pq_desc.size() && visited[pq_desc.top()] == 0)
			{
				pq_desc.pop();
			}
			while (pq_asc.size() && visited[pq_asc.top()] == 0)
			{
				pq_asc.pop();
			}
		}

		if (pq_asc.empty() || pq_desc.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << pq_desc.top() << ' ' << pq_asc.top() << '\n';
		}
	}

	return 0;
}