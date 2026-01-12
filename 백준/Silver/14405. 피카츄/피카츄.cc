#include <bits/stdc++.h>
using namespace std;

string s, ret;
int len;

int main(void)
{
	cin >> s;
	len = (int)s.size();
	ret = "YES";

	for (int i = 0; i < len;)
	{
		if (len < i + 2)
		{
			ret = "NO";
			break;
		}

		bool pass = false;
		if (len >= i + 2)
		{
			if ((s[i] == 'p' && s[i + 1] == 'i') ||
				(s[i] == 'k' && s[i + 1] == 'a'))
			{
				pass = true;
				i += 2;
			}
		}

		if (pass == false && len >= i + 3)
		{
			if (s[i] == 'c' && s[i + 1] == 'h' && s[i + 2] == 'u')
			{
				pass = true;
				i += 3;
			}
		}

		if (pass == false)
		{
			ret = "NO";
			break;
		}
	}

	cout << ret << '\n';

	return 0;
}