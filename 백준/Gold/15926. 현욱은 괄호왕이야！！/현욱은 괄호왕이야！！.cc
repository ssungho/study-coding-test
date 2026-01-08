#include <bits/stdc++.h>
using namespace std;

int n, len;
string str;
stack<int> s;

int main(void)
{
	cin >> n;
	cin >> str;

	s.push(-1);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			s.push(i);
		}
		else
		{
			s.pop();
			if (s.empty() == false)
			{
				len = max(len, i - s.top());
			}
			else
			{
				s.push(i);
			}
		}
	}

	cout << len << '\n';

	return 0;
}