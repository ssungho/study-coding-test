#include<iostream>
#include<queue>
using namespace std;

/// 최소 힙
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp != 0)
			pq.push(temp);
		else
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}