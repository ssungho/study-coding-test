#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	stack<int> s;
	queue<char> oper;

	// 마지막 숫자
	int num = 1;

	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		while (num <= temp)
		{
			s.push(num);
			num++;
			oper.push('+');
		}

		if (s.top() == temp)
		{
			s.pop();
			oper.push('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	while (!oper.empty())
	{
		cout << oper.front() << '\n';
		oper.pop();
	}
	
	return 0;
}