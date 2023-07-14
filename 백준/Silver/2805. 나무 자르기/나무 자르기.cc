#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool FindMaxHeight(long middle_value, long target, vector<long> vec)
{
	long long cnt = 0;

	for (int i = 0; i < vec.size(); i++)
		if (vec[i] - middle_value > 0)
			cnt += (vec[i] - middle_value);

	if (cnt >= target)
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

	vector<long> trees;
	long tree;
	for (int i = 0; i < N; i++)
	{
		cin >> tree;
		trees.push_back(tree);
	}
	sort(trees.begin(), trees.end());

	long start_h = 0;
	long end_h = trees[N - 1];
	long max_h = 0;

	while (start_h <= end_h)
	{
		long mid = (start_h + end_h) / 2;
		if (FindMaxHeight(mid, M, trees))
		{
			max_h = max(max_h, mid);
			start_h = mid + 1;
		}
		else
			end_h = mid - 1;
	}

	cout << max_h;
	return 0;
}