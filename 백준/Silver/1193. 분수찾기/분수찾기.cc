#include <iostream>

using namespace std;

int main(void)
{
    int X;
    cin >> X;

    int n = 1;

    while (X > n)
    {
        X -= n;
        n++;
    }

    if (n % 2 == 0)
    {
        cout << X << '/' << (n - X + 1);
    }
    else
    {
        cout << (n - X + 1) << '/' << X;
    }

    return 0;
}