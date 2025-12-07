#include <bits/stdc++.h>
using namespace std;

string s, word;
int cnt, max_cnt;

int main(void)
{
	getline(cin, s);
	getline(cin, word);
	
	for (int i = 0; i < word.size(); i++)
	{
		cnt = 0;
		for (int j = i; j < (int)s.size(); j++)
		{
			int pos = s.find(word, j);
			if (pos != string::npos)
			{
				cnt++;
				j = pos + word.size() - 1;
			}
			else
			{
				break;
			}
		}
		max_cnt = max(max_cnt, cnt);
	}

	cout << max_cnt << '\n';
	
	return 0;
}