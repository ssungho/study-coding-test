#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	long cnt = 0;
	vector<long> s(N, 0);
	vector<long> c(M, 0);

	// 첫 번째 값 == 첫 번째 합배열의 값
	cin >> s[0];

	int temp; 
	for (int i = 1; i < N; i++) 
	{
		cin >> temp;
		s[i] = s[i - 1] + temp;
	}
	int new_s;
	for(int i = 0; i < N; i++)
	{
		new_s = s[i] % M;
		if (new_s == 0)
			cnt++;
		c[new_s]++;
	}
	for (int i = 0; i < M; i++)
	{
		if (c[i] > 1)
			cnt += (c[i] * (c[i] - 1) / 2);
	}
	cout << cnt;
	
	return 0;
}