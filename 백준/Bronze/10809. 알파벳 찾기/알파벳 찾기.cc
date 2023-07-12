#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s;

	cin >> s;
	for (char i = 'a'; i <= 'z'; i++)
		cout << (int)s.find(i) << " ";
	
	return 0;
}