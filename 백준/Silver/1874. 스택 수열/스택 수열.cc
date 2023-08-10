#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	stack<int> s;
	queue<char> q;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		v.push_back(number);
	}

	int current = 1;
	for (int i = 0; i < n; i++)
	{
		if (current <= v[i])
		{
			while (current <= v[i])
			{
				s.push(current);
				q.push('+');
				current++;
			}

			s.pop();
			q.push('-');
		}
		else
		{
			if (s.top() == v[i])
			{
				s.pop();
				q.push('-');
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}

	while (!q.empty())
	{
		cout << q.front() << '\n';
		q.pop();
	}

	return 0;
}