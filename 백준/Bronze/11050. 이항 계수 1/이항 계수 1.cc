#include <iostream>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	int x = 1, y = 1;

	for (int i = 0; i < k; i++)
	{
		x *= (n - i);
		y *= (k - i);
	}

	cout << x / y;

	return 0;
}