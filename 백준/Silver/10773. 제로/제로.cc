#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
	int k;
	cin >> k;
	stack<int> s;

	for (int i = 0; i < k; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp != 0)
			s.push(temp);
		else if (temp == 0)
			s.pop();
	}

	int sum = 0;

	while (s.size() > 0)
	{
		sum += s.top();
		s.pop();	
	}

	cout << sum;
}