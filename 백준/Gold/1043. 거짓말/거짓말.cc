#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
		set<int> nums;
		bool know = false;
		for (int j = 0; j < cnt; j++)
		{
			int temp;
			cin >> temp;

			nums.insert(temp);
			// 진실을 아는 집합에 존재한다면, 그 집단 전체를 진실을 아는 집단에 추가한다.
			if (count(known.begin(), known.end(), temp) > 0)
				know = true;
		}
		if (know)
			set_union(nums.begin(), nums.end(), known.begin(), known.end(), std::inserter(known, known.begin()));
		
		parties.push_back(nums);
	}
	int answer = 0;
	for(int i = 0; i < M + 1; i++)
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