#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	vector<int> scores;
	int score;

	for (int i = 0; i < N; i++)
	{
		cin >> score;
		scores.push_back(score);
	}
	sort(scores.begin(), scores.end(), greater<int>());

	cout << scores[K -1];
	return 0;
}