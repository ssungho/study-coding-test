#include <bits/stdc++.h>
using namespace std;

string s, word;
int cnt, pos;

int main(void)
{
	getline(cin, s);
	getline(cin, word);

	while (true)
	{
		pos = s.find(word, pos);
		if (pos == string::npos)
		{
			break;
		}

		cnt++;
		pos += (int)word.size();
	}

	cout << cnt << '\n';

	return 0;
}