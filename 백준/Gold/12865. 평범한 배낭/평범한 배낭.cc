#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int memo[101][100001]{};

int main(void)
{
    int N, K;
    cin >> N >> K;

    int wv[101][2]{};

    for (int i = 1; i <= N; i++)
    {
        cin >> wv[i][0] >> wv[i][1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j < wv[i][0])
            {
                memo[i][j] = memo[i - 1][j];
            }
            else
            {
                int current_w = wv[i][0];
                int current_v = wv[i][1];
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - current_w] + current_v);
            }
        }
    }

    cout << memo[N][K];

    return 0;
}