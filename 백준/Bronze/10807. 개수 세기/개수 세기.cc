#include<iostream>
using namespace std;

int main(void) 
{
	int N;
	int v;
	int total = 0;

	cin >> N;

	int nums[100];

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	cin >> v;

	for (int i = 0; i < N; i++)
	{
		if (nums[i] == v)
			total++;
	}

	cout << total;
	
	return 0;
}