#include <iostream>
using namespace std;

int main(void)
{
	bool students[30];
	int num = 0;

	for (int i = 0; i < 30; i++)
	{
		students[i] = false;
	}

	for (int i = 0; i < 28; i++)
	{
		cin >> num;
		num--;
		students[num] = true;
	}

	for (int i = 0; i < 30; i++)
	{
		if (students[i] == false) 
		{
			cout << i + 1 << '\n';
		}
	}
	return 0;
}