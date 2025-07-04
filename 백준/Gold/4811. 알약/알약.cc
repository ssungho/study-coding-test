#include <iostream>

using namespace std;

unsigned long long dp[31][31]{};

unsigned long long Search(int w, int h)
{
    if (w == 0 && h == 0)
        return 1;

    unsigned long long& get = dp[w][h];

    if (get)
        return get;

    if (w > 0)
        get += Search(w - 1, h + 1);
    if (h > 0)
        get += Search(w, h - 1);

    return get;
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