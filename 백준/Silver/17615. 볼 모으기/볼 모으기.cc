#include <bits/stdc++.h>
using namespace std;

string s;
int b, r, len, result;

template <typename T>
int count(T begin, T end, char color)
{
	bool start = false;
	int cnt = 0;

	for (T cur = begin; cur != end; cur++)
	{
		if (*cur == color && start)
		{
			cnt++;
		}

		if (false == start && *cur != color)
		{
			start = true;
		}
	}
	
	return cnt;
}

int main(void)
{
	cin >> len >> s;

	for (int i = 0; i < len; i++)
	{
		s[i] == 'R' ? r++ : b++;
	}

	result = min(r, b);
	result = min(result, count(s.begin(), s.end(), 'R'));
	result = min(result, count(s.rbegin(), s.rend(), 'R'));
	result = min(result, count(s.begin(), s.end(), 'B'));
	result = min(result, count(s.rbegin(), s.rend(), 'B'));

	cout << result << '\n';

	return 0;
}