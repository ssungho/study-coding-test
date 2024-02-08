#include <iostream>
#include <algorithm>
using namespace std;

int costs[1000][3];
int memo[1000][3];

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> costs[i][j];

    memo[0][0] = costs[0][0];
    memo[0][1] = costs[0][1];
    memo[0][2] = costs[0][2];

    for (int i = 1; i < N; i++)
    {
        memo[i][0] = costs[i][0] + min(memo[i - 1][1], memo[i - 1][2]);
        memo[i][1] = costs[i][1] + min(memo[i - 1][0], memo[i - 1][2]);
        memo[i][2] = costs[i][2] + min(memo[i - 1][0], memo[i - 1][1]);
    }

    cout << min({memo[N - 1][0], memo[N - 1][1], memo[N - 1][2]});

    return 0;
}