#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T > 0)
	{
		queue<pair<int, int>> q;
		vector<int> v;
		int N, M;
		cin >> N >> M; // N은 개수, M은 찾을 문서의 인덱스
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			q.push({ i,temp }); // 인덱스와 중요도 저장
			v.push_back(temp); // 중요도 저장
		}
		sort(v.begin(), v.end());
		int cnt = 1;
		while (true)
		{
			if (q.front().first == M && q.front().second == v.back())
				break;
			else 
			{
				if (q.front().second == v.back())
				{
					v.pop_back();
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