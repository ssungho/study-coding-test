#include<iostream>
#include<queue>

using namespace std;

int main(void) 
{
	int N;
	cin >> N;

	queue<int> queue;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "push")
		{
			int x;
			cin >> x;
			queue.push(x);
		}
		else 
		{
			if (temp == "pop")
			{
				if (queue.empty())
					cout << -1;
				else
				{
					int x = queue.front();
					cout << queue.front();
					queue.pop();
				}
			}

			else if (temp == "size")
				cout << queue.size();
			

			else if (temp == "empty")
			{
				if (queue.empty())
					cout << 1;
				else
					cout << 0;
			}

			else if (temp == "front")
			{
				if (queue.empty())
					cout << -1;
				else
					cout << queue.front();
			}

			else if (temp == "back")
			{
				if (queue.empty())
					cout << -1;
				else
					cout << queue.back();
			}

			cout << '\n';
		}
	}

	return 0;
}