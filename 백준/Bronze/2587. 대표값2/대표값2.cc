#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	vector<int> scores;
	int sum = 0;
	int score;
	for (int i = 0; i < 5; i++)
	{
		cin >> score;
		sum += score;
		scores.push_back(score);
	}

	sort(scores.begin(), scores.end());

	cout << sum / 5 << '\n';
	cout << scores[2];

	return 0;
}