#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	queue<int> q;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (temp == "pop")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (temp == "size")
		{
			cout << q.size() << '\n';
		}
		else if (temp == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (temp == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (temp == "back")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
	return 0;
}