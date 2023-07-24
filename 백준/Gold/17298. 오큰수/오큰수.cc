#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
	int N;
	cin >> N;
	
	vector<int> answer(N + 1); // 정답 배열
	vector<int> v(N + 1); // 입력 받을 배열
	stack<int> s; // 스택

	for (int i = 1; i < N + 1; i++)
	{
		int temp;
		cin >> temp;
		v[i] = temp;
	}

	for (int i = 1; i < N + 1; i++)
	{
		while (!s.empty() && s.top() < i && v[s.top()] < v[i])
		{
			answer[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty())
	{
		answer[s.top()] = -1;
		s.pop();
	}

	for (int i = 1; i < N + 1; i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}