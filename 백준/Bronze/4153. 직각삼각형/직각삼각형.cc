#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int lines[3];
	while (true)
	{
		cin >> lines[0] >> lines[1] >> lines[2];

		if (lines[0] == 0 && lines[1] == 0 && lines[2] == 0)
			break;

		sort(lines, lines + 3);

		if (pow(lines[0], 2) + pow(lines[1], 2) == pow(lines[2], 2))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	return 0;
}