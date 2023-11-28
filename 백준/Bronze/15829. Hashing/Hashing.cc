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

	for (int i = 0; i < l; i++)
	{
		char c = str[i];

		long long ll = c - 'a' + 1;
		ll *= r;
		sum += ll;

		r *= 31;
	}

	cout << sum;

	return 0;
}