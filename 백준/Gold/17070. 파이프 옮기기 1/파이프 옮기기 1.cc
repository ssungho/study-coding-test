#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int house[17][17]{};
    int memo[17][17][3]{};

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> house[i][j];
        }
    }

    memo[1][2][0] = 1;

    for (int r = 1; r <= N; r++)
    {
        for (int c = 2; c <= N; c++)
        {
            if (house[r][c] == 1)
                continue;

            if (c > 1 && house[r][c - 1] == 0)
            {
                memo[r][c][0] += memo[r][c - 1][0] + memo[r][c - 1][2];
            }

            if (r > 1 && house[r - 1][c] == 0)
            {
                memo[r][c][1] += memo[r - 1][c][1] + memo[r - 1][c][2];
            }

            if (r > 1 && c > 1 && house[r][c - 1] == 0 && house[r - 1][c] == 0)
            {
                memo[r][c][2] += memo[r - 1][c - 1][0] + memo[r - 1][c - 1][1] + memo[r - 1][c - 1][2];
            }
        }
    }

    cout << memo[N][N][0] + memo[N][N][1] + memo[N][N][2];

    return 0;
}