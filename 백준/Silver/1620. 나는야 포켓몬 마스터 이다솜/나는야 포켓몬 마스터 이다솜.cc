#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	map<string,int> dict;
	vector<string> name;
	vector<string> answer;

	for (int i = 1; i < N + 1; i++)
	{
		string temp;
		cin >> temp;

		name.push_back(temp);
		dict.insert(make_pair(temp, i));
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		// char 65~90 대문자
		if (temp[0] <= 90 && temp[0] >= 65)
			answer.push_back(to_string(dict[temp]));
		else
			answer.push_back(name[stoi(temp) - 1]);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}