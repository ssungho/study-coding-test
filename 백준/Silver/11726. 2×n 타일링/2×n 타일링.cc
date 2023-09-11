#include <iostream>
using namespace std;

long long memo[1001];
int main(void)
{
    long long n;
    cin >> n;
    memo[1] = 1;
    memo[2] = 2;
    for(int i = 3; i < n + 1; i++)
    {
        memo[i] = (memo[i-1] + memo[i-2]) % 10007;
    }
    cout << memo[n];
    return 0;
}