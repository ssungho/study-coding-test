#include<iostream>

int main(void) 
{
	int a, b;
	std::cin >> a >> b;
	
	if (a > b) 
		std::cout << '>';
	
	if (a < b) 
		std::cout << '<';
	
	if (a == b) 
		std::cout << "==";
	
    return 0;
}