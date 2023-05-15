#include<iostream>
using namespace std;

int main(void) 
{
	int N, X;
	cin >> N >> X;
	
	int nums[10000];

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++)
	{
		if (nums[i] < X)
			cout << nums[i] << " ";
	}
	
	return 0;
}