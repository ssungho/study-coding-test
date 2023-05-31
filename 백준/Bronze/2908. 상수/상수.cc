#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	string num1, num2;
	cin >> num1 >> num2;

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int i_num1, i_num2;

	i_num1 = stoi(num1);
	i_num2 = stoi(num2);

	cout << max(i_num1, i_num2);
	
	return 0;
}