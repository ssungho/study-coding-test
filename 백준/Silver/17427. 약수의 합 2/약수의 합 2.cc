#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;

    ull sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i * (n / i);
    }

    cout << sum << endl;
    return 0;
}