#include <bits/stdc++.h>
using namespace std;
using pair_d_ii = pair<double, pair<int, int>>;

int n, parents[100];
double pos[100][2], ret;

int Find(int a)
{
	if (parents[a] == a)
	{
		return a;
	}

	return parents[a] = Find(parents[a]);
}

bool Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa != pb)
	{
		parents[pb] = pa;
		return true;
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i][0] >> pos[i][1];
	}

	vector<pair_d_ii> v;
	v.reserve(n * (n - 1) / 2);

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (i != j)
			{
				double cost = sqrt
				(
					pow(pos[i][0] - pos[j][0], 2) +
					pow(pos[i][1] - pos[j][1], 2)
				);

				v.push_back({cost, {i, j}});
			}
		}
	}

	sort(v.begin(), v.end(), less<>());

	for (int i = 0; i < n; i++)
	{
		parents[i] = i;
	}

	for (auto& ele : v)
	{
		double cost = ele.first;
		int node1 = ele.second.first;
		int node2 = ele.second.second;

		if (Union(node1, node2) == true)
		{
			ret += cost;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ret << '\n';

	return 0;
}