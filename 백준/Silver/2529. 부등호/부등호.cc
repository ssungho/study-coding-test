#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

bool visited[10];
int n;
ull max_num, min_num;
char ex[10];
vector<ull> temp;

void go(int here, int cnt)
{
	if (cnt == n)
	{
		ull num = 0;
		for (int i : temp)
		{
			num *= 10;
			num += i;
		}
		max_num = max(max_num, num);
		min_num = min(min_num, num);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i])
		{
			continue;
		}

		int back = temp.back();
		if ((ex[cnt] == '<' && back < i) || (ex[cnt] == '>' && back > i))
		{
			visited[i] = true;
			temp.push_back(i);
			go(i, cnt + 1);
			temp.pop_back();
			visited[i] = false;
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ex[i];
	}

	max_num = 0;
	min_num = ULONG_LONG_MAX;

	for (int i = 0; i < 10; i++)
	{
		temp.push_back(i);
		visited[i] = true;
		go(i, 0);
		visited[i] = false;
		temp.pop_back();
	}

	string str_max_num = to_string(max_num);
	while (str_max_num.size() < n + 1)
	{
		str_max_num = '0' + str_max_num;
	}

	string str_min_num = to_string(min_num);
	while (str_min_num.size() < n + 1)
	{
		str_min_num = '0' + str_min_num;
	}

	cout << str_max_num << '\n';
	cout << str_min_num << '\n';

	return 0;
}