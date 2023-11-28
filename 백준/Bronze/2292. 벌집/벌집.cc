#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int temp = 1;
	int answer = 1;

	while (n > temp)
	{
		temp = temp + 6 * answer;
		answer++;
	}

	cout << answer;

	return 0;
}