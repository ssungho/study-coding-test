#include <iostream>

using namespace std;

int cards[1001];
int memo[1001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> cards[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            memo[i] = max(memo[i], memo[i - j] + cards[j]);
        }
    }

    cout << memo[n];

    return 0;
}