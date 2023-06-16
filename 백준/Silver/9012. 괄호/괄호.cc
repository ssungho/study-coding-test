#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string ps;
		cin >> ps;

		vector<char> v;
		bool result = true;

		for (int j = 0; j < ps.length(); j++)
		{
			if (ps[j] == '(')
				v.push_back(ps[j]);

			if (ps[j] == ')')
			{
				if (v.empty() || v.back() != '(')
				{
					result = false;
					break;
				}

				else if (v.back() == '(')
					v.pop_back();
			}
		}

		if (v.size() > 0)
			result = false;

		if (result == true)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}