#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int sum = 0;
		int ctor = i;

		while (ctor > 0)
		{
			sum += (ctor % 10);
			ctor /= 10;
		}

		sum += i;

		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}