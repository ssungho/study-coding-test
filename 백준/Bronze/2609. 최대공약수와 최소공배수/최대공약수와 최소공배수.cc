#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{
	if (num2 > num1)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	while (num2 > 0) 
	{
		int temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}

	return num1;
}

int lcm(int num1, int num2) 
{
	return (num1 * num2) / gcd(num1, num2);
}

int main(void)
{
	int num1, num2;
	cin >> num1 >> num2;

	cout << gcd(num1, num2) << endl;
	cout << lcm(num1, num2) << endl;

	return 0;
}