#include <bits/stdc++.h>
using namespace std;

int n, h, bi, ti, ret, cnt, bottom[200001], top[200001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> h;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			cin >> bottom[bi++];
		}
		else
		{
			cin >> top[ti++];
		}
	}

	sort(bottom, bottom + bi);
	sort(top, top + ti);
	ret = n;

	int cnt_bottom, cnt_top, cnt_total;
	for (int height = 1; height <= h; height++)
	{
		cnt_bottom = bi - (lower_bound(bottom, bottom + bi, height) - bottom);
		cnt_top = ti - (lower_bound(top, top + ti, h - height + 1) - top);
		cnt_total = cnt_bottom + cnt_top;

		if (cnt_total < ret)
		{
			ret = cnt_total;
			cnt = 1;
		}
		else if (cnt_total == ret)
		{
			cnt++;
		}
	}

	cout << ret << ' ' << cnt << '\n';

	return 0;
}