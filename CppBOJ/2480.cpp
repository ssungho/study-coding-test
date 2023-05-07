#include<iostream>
#include<algorithm>
using namespace std;

int main(void) 
{
	int a, b, c, Max;
	cin >> a >> b >> c;

	if (a == b || b == c || c == a) 
	{
		if (a == b && b == c)
			cout << 10000 + a * 1000;
		else if (a == b)
			cout << 1000 + a * 100;
		else
			cout << 1000 + c * 100;
	}
	else
	{
		Max = max(max(a, b), c);
		cout << Max * 100;
	}
}