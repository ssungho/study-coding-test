#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= v.at(i); j++)
		{
			if (v.at(i) % j == 0)
				cnt++;
		}

		if (cnt == 2) 
		{
			answer++;
		}
	}

	cout << answer;

	return 0;
}