#include <iostream>
#include <queue>

using  namespace std;

int main(void)
{
	int n;
	cin >> n;

	queue<int> cards;

	for (int i = 1; i < n + 1; i++)
	{
		cards.push(i);
	}

	while (cards.size() > 1)
	{
		cards.pop();
		
		int temp = cards.front();
		cards.push(temp);
		cards.pop();
	}

	cout << cards.front();

	return 0;
}