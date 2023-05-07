#include<iostream>
using namespace std;

int main(void) 
 {
	int h, m, need;

	cin >> h >> m >> need;

	h += need / 60;
	m += need % 60;
	if (m >= 60) 
 {
		h += m / 60;
		m %= 60;
	}
	if (h >= 24)
		h -= 24;

	cout << h << " " << m;
}