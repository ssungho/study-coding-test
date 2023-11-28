#include <iostream>
using namespace std;

int main(void)
{
	int a, b, v;
	cin >> a >> b >> v;

	v -= a; 
	int answer = 1;
	int length = a - b;

	if (v % length != 0)
		answer++;
	answer += (v / length);

	cout << answer;
	return 0;
}