#include <bits/stdc++.h>

using namespace std;

const int cnt_c = 26;
const int cnt_d = 10;
string str;
int ret, cnt_seq;

int main(void)
{
	cin >> str;

	ret = str[0] == 'c' ? cnt_c : cnt_d;

	for (int i = 1; i < (int)str.size(); i++)
	{
		cnt_seq = (str[i] == str[i - 1]) ? 1 : 0;
		ret *= (str[i] == 'c') ? (cnt_c - cnt_seq) : (cnt_d - cnt_seq);
	}

	cout << ret << '\n';

	return 0;
}