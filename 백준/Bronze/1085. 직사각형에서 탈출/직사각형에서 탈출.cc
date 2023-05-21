#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << min(h - y, min(w - x, min(x, y)));

	return 0;
}