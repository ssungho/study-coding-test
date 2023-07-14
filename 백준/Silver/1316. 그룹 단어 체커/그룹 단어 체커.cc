#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int answer = 0;
	
	string temp;
	for (int i = 0; i < N; i++)
	{
		vector<char> v;
		int cnt = 0;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			if(find(v.begin(), v.end(), temp[j]) == v.end())
				v.push_back(temp[j]);
			else
			{
				if (v.back() == temp[j])
					v.push_back(temp[j]);
				else
				{
					cnt++;
					break;
				}
			}
		}
		if (cnt == 0)
			answer++;
	}
	cout << answer;
	return 0;
}