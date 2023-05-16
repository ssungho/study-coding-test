#include <iostream>
using namespace std;

int main(void)
{
	int nums[42]{ 0 };
	int temp = 0;
	int cnt = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		nums[temp % 42]++;
	}
	
	for (int i = 0; i < 42; i++)
	{
		if (nums[i] > 0)
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}