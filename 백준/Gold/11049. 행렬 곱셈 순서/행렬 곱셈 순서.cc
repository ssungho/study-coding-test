#include <iostream>
#include <limits.h>

using namespace std;

int main(void)
{
    int matrix[501][2] = {};

    int N, r, c;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> r >> c;
        matrix[i][0] = r;
        matrix[i][1] = c;
    }

    int memo[501][501] = {};

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; i + j <= N; j++)
        {
            memo[j][i + j] = INT_MAX;
            for (int k = j; k < i + j; k++)
            {
                memo[j][i + j] = min(memo[j][i + j],
                                     memo[j][k] + memo[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }
    }

    cout << memo[1][N] << endl;
    return 0;
}