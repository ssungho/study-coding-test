#include <iostream>
#include <memory.h>
using namespace std;

int stickers[2][100001]{};
int memo[2][100001]{};

int Test()
{
    memset(stickers, 0, sizeof(int) * 100001 * 2);
    memset(memo, 0, sizeof(int) * 100001 * 2);

    int n;
    cin >> n;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> stickers[i][j];
        }
    }

    if (n == 1)
        return max(stickers[0][1], stickers[1][1]);

    memo[0][1] = stickers[0][1];
    memo[1][1] = stickers[1][1];
    memo[0][2] = stickers[0][2] + memo[1][1];
    memo[1][2] = stickers[1][2] + memo[0][1];


    for (int i = 3; i <= n; i++)
    {
        memo[0][i] = max(memo[1][i - 2], memo[1][i - 1]) + stickers[0][i];
        memo[1][i] = max(memo[0][i - 2], memo[0][i - 1]) + stickers[1][i];
    }

    return max(memo[0][n], memo[1][n]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cout << Test() << endl;
    }

    return 0;
}