#include <bits/stdc++.h>
using namespace std;

int l, c;
char ch;
string s, password = "";

void go(int here, int consonants, int vowels, int cnt)
{
	if (cnt == l && consonants >= 2 && vowels >= 1)
	{
		cout << password << '\n';
		return;
	}

	for (int i = here; i < (int)s.size(); i++)
	{
		password.push_back(s[i]);
		
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			go(i + 1, consonants, vowels + 1, cnt + 1);
		}
		else
		{
			go(i + 1, consonants + 1, vowels, cnt + 1);
		}

		password.pop_back();
	}
}

int main(void)
{
	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> ch;
		s.push_back(ch);
	}

	sort(s.begin(), s.end());
	go(0, 0, 0, 0);

	return 0;
}