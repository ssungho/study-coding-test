#include<iostream>

using namespace std;

int main(void)
{
	int a, b, c, d ,e;
	cin >> a >> b;

	c = a * (b % 10);
	b /= 10;
	d = a * (b % 10);
	b /= 10;
	e = a * (b % 10);

	cout << c << "\n";
	cout << d << "\n";
	cout << e << "\n";
	cout << c + d * 10 + e * 100;
	
	return 0;
}
