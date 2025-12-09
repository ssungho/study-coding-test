#include <bits/stdc++.h>
using namespace std;

int n, s_cnt, ll_cnt, min_cnt;
string s;

int main(void)
{
	cin >> n >> s;
	for (char ch : s)
	{
		ch == 'S' ? s_cnt++ : ll_cnt++;
	}
	ll_cnt /= 2;

	min_cnt = min(s_cnt + ll_cnt  + 1, n);
	cout << min_cnt << '\n';

	return 0;
}