#include<iostream>
#include<algorithm>

using namespace std;

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
{
	if (a.second.first == b.second.first)
		return a.first < b.first;
	else
		return a.second.first < b.second.first;
	
}

int main(void)
{
	int n;
	cin >> n;

	pair<int,pair<int,string>> * nums = new pair<int, pair<int, string>>[n]; // 동적 할당

	for(int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		nums[i].first = i;
		nums[i].second.first = age;
		nums[i].second.second = name;
	}

	sort(nums, nums + n, compare);

	for (int i = 0; i < n; i++)
	{
		cout << nums[i].second.first << " " << nums[i].second.second << '\n';
	}

	return 0;
}