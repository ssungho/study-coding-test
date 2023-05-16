#include<iostream>
using namespace std;

int main(void) 
{
	int nums[9];
	int max = INT32_MIN;
	int seq = 0;

	for (int i = 0; i < size(nums); i++)
	{
		cin >> nums[i];
		if (nums[i] > max) 
		{
			max = nums[i];
			seq = i + 1;
		}
	}

	cout << max << '\n' << seq;

	return 0;
}