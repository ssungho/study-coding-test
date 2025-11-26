#include <bits/stdc++.h>
using namespace std;

int n;
bool finished;

bool check(const string& str)
{
	int size = str.size();
	if (size >= 1)
	{
		for (int i = size; i > 0; i--)
		{
			if (i % 2 == 0)
			{
				int half = i / 2;
				bool matched = true;

				for (int j = 1; j <= half; j++)
				{
					if (str[size - j] != str[size - half - j])
					{
						matched = false;
					}
				}

				if (matched)
				{
					return false;
				}
			}
		}
	}

	return true;
}

void go(int cnt, const string& str)
{
	if (cnt == n)
	{
		cout << str << '\n';
		finished = true;
		return;
	}

	for (char ch = '1'; ch <= '3'; ch++)
	{
		if (check(str + ch))
		{
			go(cnt + 1, str + ch);
		}

		if (finished)
		{
			return;
		}
	}
}

int main(void)
{
	cin >> n;
	go(0, "");
	return 0;
}