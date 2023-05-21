#include<iostream>
using namespace std;

int main()
{
	int t, h, w, n;
	int room;
	cin >> t;
	for (int i = 0; i < t; i++) 
	{
		cin >> h >> w >> n;
		
		if (n % h > 0)
		{
			room = (n % h) * 100 + n / h + 1;
		}
		else
		{
			room = h * 100 + n / h;
		}

		cout << room << '\n';
	}
	return 0;
}