#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = N - 1;
	int cnt = 0;
	while (start != end)
	{
		if (v[start] + v[end] == M)
		{
			cnt++;
			end--;
		}
		else if (v[start] + v[end] > M)
			end--;

		else if (v[start] + v[end] < M)
			start++;
	}
	cout << cnt;
	return 0;
}