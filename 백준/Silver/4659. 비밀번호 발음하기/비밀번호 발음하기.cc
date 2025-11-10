#include <bits/stdc++.h>
using namespace std;

string password;

bool is_vowel(char ch)
{
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		cin >> password;

		if (password == "end")
		{
			break;
		}

		int seq_v = 0;
		int seq_c = 0;
		bool can = true;
		bool contain = false;
		char prev = ' ';

		for (int i = 0; i < (int)password.length(); i++)
		{
			if (is_vowel(password[i]))
			{
				seq_v++;
				seq_c = 0;
				contain = true;

				if (seq_v > 1 && prev == password[i])
				{
					if (!(prev == 'e' || prev == 'o'))
					{
						can = false;
						break;
					}
				}
			}
			else
			{
				seq_c++;
				seq_v = 0;
				if (prev == password[i])
				{
					can = false;
					break;
				}
			}

			if (seq_v >= 3 || seq_c >= 3)
			{
				can = false;
				break;
			}

			prev = password[i];
		}

		if (can && contain)
			cout << "<" << password << "> " << "is acceptable.\n";
		else
			cout << "<" << password << "> " << "is not acceptable.\n";
	}

	return 0;
}