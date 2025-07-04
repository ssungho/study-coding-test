#include <iostream>

using namespace std;

unsigned long long dp[31][31]{};

unsigned long long Search(int w, int h)
{
    if (w == 0 && h == 0)
        return 1;

    if (dp[w][h])
        return dp[w][h];

    if (w > 0)
        dp[w][h] = dp[w][h] + Search(w - 1, h + 1);
    if (h > 0)
        dp[w][h] = dp[w][h] + Search(w, h - 1);

    return dp[w][h];
}

int main(void)
{
    int T;
    while (cin >> T && T != 0)
    {
        cout << Search(T, 0) << '\n';
    }

    return 0;
}