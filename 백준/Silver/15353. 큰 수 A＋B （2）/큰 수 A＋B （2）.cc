#include <bits/stdc++.h>
using namespace std;

string a, b, ret;
int size_a, size_b, min_len, max_len;
int sum, i_a, i_b, alpha;

void last_add(const string& s)
{
	for (int i = min_len; i < max_len; i++)
	{
		sum = s[i] - '0' + alpha;
		alpha = sum / 10;
		ret[i] = sum % 10 + '0';
	}
}

int main(void)
{
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	size_a = (int)a.size();
	size_b = (int)b.size();
	min_len = min(size_a, size_b);
	max_len = max(size_a, size_b);

	ret = string(" ", max_len);
	for (int i = 0; i < min_len; i++)
	{
		i_a = a[i] - '0';
		i_b = b[i] - '0';
		sum = i_a + i_b + alpha;
		alpha = sum / 10;
		ret[i] = sum % 10 + '0';
	}

	size_a > size_b ? last_add(a) : last_add(b);
	if (alpha == 1)
	{
		ret.append("1");
	}

	reverse(ret.begin(), ret.end());
	cout << ret << '\n';

	return 0;
}