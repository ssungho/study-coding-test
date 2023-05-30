#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int m, n;

	cin >> m >> n;

	int* prime = new int[n + 1];
	
	for (int i = 0; i < n + 1; i++)
	{
		if (i == 0 || i == 1)
			prime[i] = 0;
		else
			prime[i] = i;
	}

	for (int i = 2; i < n + 1; i++) 
	{
		if (prime[i] == 0) 
			continue;

		for (int j = i + i; j < n + 1; j += i) 
		{
			prime[j] = 0;
		}
	}

	for (int i = m; i < n + 1; i++)
	{
		if (prime[i] != 0)
			cout << prime[i] << '\n';
	}

	return 0;
}