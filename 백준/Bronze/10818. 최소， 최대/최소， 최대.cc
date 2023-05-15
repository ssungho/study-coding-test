#include<iostream>
#include<cmath>
using namespace std;

int main(void) 
{
	int N;
	cin >> N;

	int max = INT32_MIN;
	int min = INT32_MAX;

	int nums[1000000];

	for(int i = 0; i < N; i++)
		cin >> nums[i];
	
	for (int i = 0; i < N; i++)
		if (max <= nums[i])
			max = nums[i];

	for (int i = 0; i < N; i++)
		if (min >= nums[i])
			min = nums[i];
	
	cout << min << " " << max;

	return 0;
}