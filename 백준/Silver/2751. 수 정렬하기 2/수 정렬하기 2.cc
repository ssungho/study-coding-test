#include<iostream>
#include<algorithm>

int main(void)
{
	using namespace std;

	int N;
	cin >> N;
	
	int *nums = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	sort(nums, nums + N);
	 
	for (int i = 0; i < N; i++)
	{
		cout << nums[i] << '\n';
	}
}