#include <iostream>
#include <vector>

using namespace std;

int C[1001][1001]{};

int main(void)
{
    int N, K;
    cin >> N >> K;

    int n = N + K - 1;
    int r = K;

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
            C[i][j] %= 1000000000;
        }
    }

    cout << C[n][r - 1];

    return 0;
}