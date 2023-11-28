#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	while (true)
	{
		string num = "";
		cin >> num;
		if (num == "0")
			break;
		
		string result = "yes";
		for (int i = 0; i < num.length() / 2; i++)
		{
			if (num[i] != num[num.length() - i - 1])
			{
				result = "no";
				break;
			}
		}

		cout << result << endl;
	}

	return 0;
}