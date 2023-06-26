#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	int cnt = 0;

	stack<int> s;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		s.push(temp);
	}

	for (int i = 0; i < N; i++)
	{
		temp = s.top();
		if (K / temp >= 1)
		{
			cnt += K / temp;
			K -= (temp * (K / temp));
		}
		s.pop();
	}

	cout << cnt;

	return 0;
}