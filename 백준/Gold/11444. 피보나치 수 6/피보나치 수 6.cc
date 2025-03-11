#include <iostream>
#include <map>

using namespace std;

using ull = unsigned long long;

map<ull, ull> m;
ull mod = 1000000007;

ull Fibonacci(ull n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (m.count(n) > 0)
        return m[n];

    ull mid, temp1, temp2;

    if (n % 2 == 0)
    {
        mid = n / 2;
        temp1 = Fibonacci(mid - 1);
        temp2 = Fibonacci(mid);
        m[n] = ((2 * temp1 + temp2) * temp2) % mod;
    }
    else
    {
        mid = (n + 1) / 2;
        temp1 = Fibonacci(mid);
        temp2 = Fibonacci(mid - 1);
        m[n] = (temp1 * temp1 + temp2 * temp2) % mod;
    }

    return m[n];
}

int main(void)
{
    ull n;

    cin >> n;

    cout << Fibonacci(n);

    return 0;
}