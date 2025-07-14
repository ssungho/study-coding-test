#include <iostream>
#include <vector>

using namespace std;

constexpr long long mod{1000000000};

int main(void)
{
    int n;
    cin >> n;

    int abs_n = abs(n);
    vector<long long> fibo(1000001, 0);
    fibo[1] = 1;

    for (int i = 2; i <= abs_n; i++)
    {
        fibo[i] = (fibo[i - 1] % mod + fibo[i - 2] % mod) % mod;
    }

    int answer = 0;
    
    if (n > 0)
        answer = 1;
    else if (n < 0)
    {
        if ((abs_n % 2) == 0)
            answer = -1;
        else
            answer = 1;
    }

    cout << answer << '\n';
    cout << fibo[abs_n] << '\n';

    return 0;
}