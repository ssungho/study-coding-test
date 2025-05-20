#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> array(n + 1, vector<char>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;

        for (int j = 1; j <= m; j++)
        {
            array[i][j] = row[j - 1];
        }
    }

    int max_size = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (array[i][j] == '1')
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                
                if (dp[i][j] > max_size)
                {
                    max_size = dp[i][j];
                }
            }
        }
    }

    cout << max_size * max_size;

    return 0;
}