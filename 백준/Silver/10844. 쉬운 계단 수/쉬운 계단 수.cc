#include <iostream>
using namespace std;

long long mod = 1000000000;
long long memo[101][10]{};

int main(void)
{
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        memo[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j > 0) 
            {
                memo[i][j] = (memo[i][j] + memo[i - 1][j - 1]) % mod;
            }

            if (j < 9)
            {
                memo[i][j] = (memo[i][j] + memo[i - 1][j + 1]) % mod;
            }
        }
    }

    long long answer = 0;
    for (int i = 0; i < 10; i++)
    {
        answer = (answer + memo[N][i]) % mod;
    }

    cout << answer;

    return 0;
}