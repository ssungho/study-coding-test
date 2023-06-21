#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool func(long long mid, int N, vector<int> v)
{
	long long cnt = 0;
	for (int i = 0; i < v.size(); i++)
		cnt += v[i] / mid;

	if (cnt >= N)
		return true;
	else
		return false;
}

int main(void)
{
	int K, N;
	cin >> K >> N;

	vector<int> v;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	long long first = 1;
	long long last = v[K-1];
	long long max_len = 0;

	while (first <= last)
	{
		long long mid = (first + last) / 2;

		if (func(mid, N, v))
		{
			max_len = std::max(mid, max_len);
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}
	}
	cout << max_len;
	return 0;
}