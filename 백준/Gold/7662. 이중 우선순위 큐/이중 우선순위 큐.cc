#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

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
		cin >> k;

		priority_queue<pii, vector<pii>, greater<pii>> pq_asc;
		priority_queue<pii> pq_desc;
		vector<bool> visited(k);

		for (int i = 0; i < k; i++) 
		{
			cin >> op >> num;
			if (op == 'I')
			{
				pq_asc.push({num, i});
				pq_desc.push({num, i});
				visited[i] = true;
			}
			else if (op == 'D')
			{
				if (num == -1 && pq_asc.size())
				{
					visited[pq_asc.top().second] = false;
					pq_asc.pop();
				}
				if (num == 1 && pq_desc.size())
				{
					visited[pq_desc.top().second] = false;
					pq_desc.pop();
				}
			}

			while (pq_desc.size() && visited[pq_desc.top().second] == false)
			{
				pq_desc.pop();
			}
			while (pq_asc.size() && visited[pq_asc.top().second] == false)
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
			cout << pq_desc.top().first << ' ' << pq_asc.top().first << '\n';
		}
	}

	return 0;
}