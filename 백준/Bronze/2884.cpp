#include<iostream>
using namespace std;

int main(void) 
{
	int h, m;
	cin >> h >> m;

	if (m < 45)
{
		h -= 1;

		if (h < 0) 
			h += 24;

		cout << h << " " << m + 15;
	}
	else
		cout << h << " " << m - 45;
}