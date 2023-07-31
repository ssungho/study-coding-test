#include <iostream>
using namespace std;

int memo[11];

int AddOneTwoThree(int x)
{
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for (int i = 4; i < x + 1; i++)
    {
        if (memo[i] == 0)
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    return memo[x];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << AddOneTwoThree(n) << '\n';
    }
}