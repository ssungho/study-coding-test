#include <bits/stdc++.h>

using namespace std;

int a, b, c, x, y, min_cnt, result;

int main(void)
{
	cin >> a >> b >> c >> x >> y;

	a = min(a, 2 * c);
	b = min(b, 2 * c);

	if (a + b > 2 * c)
	{
		min_cnt = min(x, y);
		result += (2 * c) * min_cnt;
		result += (x > y) ? (x - min_cnt) * a : (y - min_cnt) * b;
	}
	else
	{
		result = a * x + b * y;
	}

	cout << result << '\n';

	return 0;
}