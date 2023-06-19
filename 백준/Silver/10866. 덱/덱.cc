#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	deque<int> deque;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "push_front")
		{
			int x;
			cin >> x;
			deque.push_front(x);
		}

		else if (temp == "push_back")
		{
			int x;
			cin >> x;
			deque.push_back(x);
		}

		else if (temp == "pop_front")
		{
			if (deque.empty())
				cout << -1 << '\n';
			else
			{
				cout << deque.front() << '\n';
				deque.pop_front();
			}
		}

		else if (temp == "pop_back")
		{
			if (deque.empty())
				cout << -1 << '\n';
			else
			{
				cout << deque.back() << '\n';
				deque.pop_back();
			}
		}

		else if (temp == "size")
			cout << deque.size() << '\n';

		else if (temp == "empty")
		{
			if (deque.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		else if (temp == "front")
		{
			if (deque.empty())
				cout << -1 << '\n';
			else
				cout << deque.front() << '\n';
		}

		else if (temp == "back")
		{
			if (deque.empty())
				cout << -1 << '\n';
			else
				cout << deque.back() << '\n';
		}
	}

	return 0;
}