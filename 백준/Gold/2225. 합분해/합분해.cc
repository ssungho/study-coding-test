#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1000000000;

int C[401][401]{};

int main(void)
{
    int N, K;
    cin >> N >> K;

    int n = N + K - 1;
    int r = K - 1;

    for (int i = 0; i <= n; i++)
    {
        C[i][i] = 1;
        C[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }

    cout << C[n][r];

    return 0;
}