#include <bits/stdc++.h>

using namespace std;

int n, arr[10], answer;
vector<long long> combi;

void go(int k, int next, int cnt, long long num)
{
	if (cnt == k)
	{
		combi.push_back(num);
		return;
	}
	
	for (int i = next; i < 10; i++)
	{
		go(k, i + 1, cnt + 1, num * 10 + arr[i]);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 9 - i;
	}

	for (int i = 1; i <= 10; i++)
	{
		go(i, 0, 0, 0);
		unique(combi.begin(), combi.end());
	}

	sort(combi.begin(), combi.end());

	if (combi.size() <= n)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << combi[n];
	}

	return 0;
}