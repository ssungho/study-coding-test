#include <bits/stdc++.h>

using namespace std;

int n, temp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (max_heap.empty() || temp <= max_heap.top())
		{
			max_heap.push(temp);
		}
		else
		{
			min_heap.push(temp);
		}

		if (max_heap.size() > min_heap.size() + 1)
		{
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		else if (max_heap.size() < min_heap.size())
		{
			max_heap.push(min_heap.top());
			min_heap.pop();
		}

		cout << max_heap.top() << '\n';
	}

	return 0;
}