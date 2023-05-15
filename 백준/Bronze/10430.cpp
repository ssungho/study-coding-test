#include<iostream>

int solution(void)
{
	int a, b, c;

	std::cin >> a >> b >> c;
	std::cout << ((a + b) % c) << "\n" << (((a % c) + (b % c)) % c) << "\n" << ((a * b) % c) << "\n" << (((a % c) * (b % c)) % c);

	return 0;
}