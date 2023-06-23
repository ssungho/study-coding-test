#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int set[21] = { 0 };

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "add")
		{
			int num;
			cin >> num;

		    set[num] = 1;
		}
		else if (temp == "remove")
		{
			int num;
			cin >> num;

		    set[num] = 0;
		}
		else if (temp == "check")
		{
			int num;
			cin >> num;

			cout << set[num] << '\n';
		}
		else if (temp == "toggle")
		{
			int num;
			cin >> num;

			if (set[num] == 1)
				set[num] = 0;
			else
				set[num] = 1;
		}
		else if (temp == "all")
		{
			for (int j = 0; j < 21; j++)
				set[j] = 1;
		}
		else if (temp == "empty")
		{
			for (int j = 0; j < 21; j++)
				set[j] = 0;
		}
	}

	return 0;
}