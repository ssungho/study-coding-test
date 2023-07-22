#include <iostream>
#include <queue>
using namespace std;

// boj 1966 프린터 큐
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T > 0)
	{
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int N, M;
		cin >> N >> M; // N은 개수, M은 찾을 문서의 인덱스
		for (int i = 0; i < N; i++)
		{
			int importance;
			cin >> importance;
			q.push({i, importance }); // 인덱스와 중요도 저장
			pq.push(importance);
		}

		int cnt = 1;
		while (true)
		{
			if (q.front().first == M && q.front().second == pq.top())
				break;
			else 
			{
				if (q.front().second == pq.top())
				{
					pq.pop();
					q.pop();
					cnt++;
				}
				else
				{
					q.push(q.front());
					q.pop();
				}
			}
		}
		cout << cnt << '\n';
		T--;
	}

	return 0;
}