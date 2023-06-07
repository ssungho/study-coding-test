#include<iostream>
using namespace std;

int main(void)
{
    int n;
	int answer = 0;
	cin >> n;

	for (int i = 5; i <= n; i *= 5)
		answer += n / i;
	
	cout << answer;

	return 0;
}    
