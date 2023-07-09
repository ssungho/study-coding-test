#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool FindMaxHeight(long mid, long M, vector<long> v)
{
	long long cnt = 0;

	for (int i = 0; i < v.size(); i++)
		if (v[i] - mid > 0)
			cnt += (v[i] - mid);

	if (cnt >= M)
		return true;
	else
		return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long M;
	cin >> N >> M;

	vector<long> v;
	long temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	long start = 1;
	long end = v[N - 1];
	long max_h = 0;

	while (start <= end)
	{
		long mid = (start + end) / 2;
		if (FindMaxHeight(mid, M, v))
		{
			max_h = max(max_h, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << max_h;
	return 0;
}