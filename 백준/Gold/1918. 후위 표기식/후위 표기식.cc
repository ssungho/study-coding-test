#include <bits/stdc++.h>

using namespace std;

int cmp(char ch)
{
	if (ch == '*' || ch == '/') return 2;
	if (ch == '+' || ch == '-') return 1;
	return 0;
}

int main(void)
{
	string str;
	cin >> str;

	stack<char> s;

	int len = (int)str.size();
	
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];

		if ('A' <= ch && ch <= 'Z')
		{
			cout << ch;
		}
		else if (ch == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (ch == '(')
		{
			s.push(ch);
		}
		else
		{
			while (!s.empty() && cmp(s.top()) >= cmp(ch))
			{
				cout << s.top();
				s.pop();
			}
			s.push(ch);
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	cout << '\n';

	return 0;
}