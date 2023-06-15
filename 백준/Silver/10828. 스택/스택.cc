#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "push")
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}

		else if (temp == "pop")
		{
			if (v.empty())
				cout << -1 << '\n';
			else
			{
				int temp = v.back();
				v.pop_back();
				cout << temp << '\n';
			}
		}

		else if (temp == "size")
		{
			cout << v.size() << '\n';
		}

		else if (temp == "empty")
		{
			if (v.size() > 0)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}

		else if (temp == "top")
		{
			if (v.size() > 0)
			{
				cout << v.back() << '\n';
			}

			else
			{
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}