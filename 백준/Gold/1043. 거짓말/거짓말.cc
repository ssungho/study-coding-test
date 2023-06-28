#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	set<int> known;
	int cnt;

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		int temp;
		cin >> temp;
		known.insert(temp);
	}

	vector<set<int>> parties;
	for (int i = 0; i < M; i++)
	{
		cin >> cnt;
		// 임시 집합
		set<int> nums;
		for (int j = 0; j < cnt; j++)
		{
			int temp;
			cin >> temp;
			nums.insert(temp);
		}
		parties.push_back(nums);
	}

	int answer = 0;
	for (int i = 0; i < M + 1; i++) 
	{
		if (i == M)
		{
			for (int j = 0; j < M; j++)
			{
				set<int> party = parties[j];
				set<int> temp;
				set_union(party.begin(), party.end(), known.begin(), known.end(), std::inserter(temp, temp.begin()));
				// 교집합이 없는경우
				if (temp.size() == party.size() + known.size())
					answer++;
			}
		}
		else
		{
			for (int j = 0; j < M; j++)
			{
				set<int> party = parties[j];
				set<int> temp;
				set_union(party.begin(), party.end(), known.begin(), known.end(), std::inserter(temp, temp.begin()));
				// 교집합이 없는경우
				if (temp.size() == party.size() + known.size())
					continue;
				else
					set_union(party.begin(), party.end(), known.begin(), known.end(), std::inserter(known, known.begin()));
			}
		}
	}

	cout << answer;
	return 0;
}