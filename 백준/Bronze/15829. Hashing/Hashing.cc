#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int l;
	string str;
	cin >> l >> str;

	long long sum = 0;
	long long r = 1;
	long long m = 1234567891;

	for (int i = 0; i < l; i++)
	{
		char c = str[i];
		long long ll = c + 1 - 'a';

		ll *= r;
		sum = (sum + ll) % m;
		r = r * 31 % m;
	}

	cout << sum;

	return 0;
}