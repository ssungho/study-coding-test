#include<iostream>

int main(void){
    double a, b, c;
    std::cin >> a >> b;
    c = a / b;
    std::cout.precision(15);
    std::cout << c; 
    return 0;
}