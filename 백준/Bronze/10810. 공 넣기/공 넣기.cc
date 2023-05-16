#include<iostream>
using namespace std;

int main(void) 
{
	int N, M;
	int basket[100];
	cin >> N >> M;

	for (int i = 0; i < size(basket); i++)
	{
		basket[i] = 0;
	}

	for (int i = 0; i < M; i++)
	{

		int first, last, number;

		cin >> first >> last >> number;
		
		for (int j = first - 1; j <= last - 1; j++)
		{
			basket[j] = number;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << basket[i] << " ";
	}

	return 0;
}