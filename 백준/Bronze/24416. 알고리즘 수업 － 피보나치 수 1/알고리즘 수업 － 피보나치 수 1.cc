#include <iostream>
using namespace std;
int cnt = 0;
int fib(int n)
{
    cnt++;
    if(n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
int main(void)
{
    int n;
    cin >> n;
    cout << fib(n) << " " << n - 2;

    return 0;
}