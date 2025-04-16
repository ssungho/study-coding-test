#include <iostream>

using namespace std;

int C[1001][1001]{};

int main(void)
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++)
    {
        C[i][0] = 1;
        C[i][i] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 10007;
        }
    }

    cout << C[N][K];

    return 0;
}