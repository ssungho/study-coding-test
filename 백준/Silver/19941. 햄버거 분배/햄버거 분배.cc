#include <bits/stdc++.h>
using namespace std;

int n, k, result;
string s;
queue<int> p_pos, h_pos;

int main(void)
{
	cin >> n >> k >> s;

	for (int i = 0; i < n; i++)
	{
		s[i] == 'P' ? p_pos.push(i) : h_pos.push(i);
	}

	while (!(p_pos.empty() || h_pos.empty()))
	{
		int p = p_pos.front();
		p_pos.pop();

		while (!h_pos.empty() && p - h_pos.front() > k)
		{
			h_pos.pop();
		}

		if (abs(h_pos.front() - p) <= k)
		{
			result++;
			h_pos.pop();
		}
	}

	cout << result << '\n';

	return 0;
}