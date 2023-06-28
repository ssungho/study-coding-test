#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	 
	vector<int> line;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		line.push_back(temp);
	}
	sort(line.begin(), line.end());

	vector<int> total_time;
	total_time.push_back(0);
	int answer = 0;
	for (int i = 1; i < N + 1; i++)
	{
		int temp = total_time[i-1] + line[i - 1];
		total_time.push_back(temp);
		answer += total_time[i];
	}
	cout << answer;
	return 0;
}