#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int x;
	string y;
	cin >> x;
	for (int i = 0; i < (x / 4); i++)
	{
		y += "long ";
	}
	y += "int";

	cout << y;
}