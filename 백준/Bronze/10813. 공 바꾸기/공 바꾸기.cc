#include <iostream>
using namespace std;

int main(void)
{
	int n, m, basket1, basket2;

	cin >> n >> m;

	int baskets[100];
	for (int i = 1; i <= n; i++)
	{
		baskets[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> basket1 >> basket2;

		int temp = baskets[basket1];
		baskets[basket1] = baskets[basket2];
		baskets[basket2] = temp;
	}

	for (int i = 1; i <= n; i++) 
	{
		cout << baskets[i] << " ";
	}
	return 0;
}