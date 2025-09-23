#include <bits/stdc++.h>

using namespace std;

int n, k, max_cnt;
bool arr[26];
vector<char> temp;
vector<string> words;

void go(int next, int cnt)
{
	if (cnt == 0)
	{
		int cur_cnt = 0;
		for (auto& word : words)
		{
			bool pass = true;
			for (auto ch : word)
			{
				if (!arr[ch - 'a'])
				{
					pass = false;
					break;
				}
			}
			if (pass)
			{
				cur_cnt++;
			}
		}

		max_cnt = max(max_cnt, cur_cnt);
		return;
	}

	for (int i = next; i < 21; i++)
	{
		arr[temp[i]] = true;
		go(i + 1, cnt - 1);
		arr[temp[i]] = false;
	}
}

int main(void)
{
	cin >> n >> k;
	words.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}

	for (int i = 'a'; i <= 'z'; i++)
	{
		if (i == 'a' || i == 'c' || i == 'i' || i == 'n' || i == 't')
		{
			arr[i - 'a'] = true;
		}
		else
		{
			temp.push_back(i - 'a');
		}
	}

	if (k >= 5)
	{
		go(0, k - 5);
	}

	cout << max_cnt << '\n';

	return 0;
}