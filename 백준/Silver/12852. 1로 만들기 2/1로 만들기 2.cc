#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> dp(N + 1, INT_MAX);
    vector<int> path(N + 1, 0);
    dp[N] = 0;

    for (int i = N; i > 0; i--)
    {
        int prev = 0;
        if (i % 3 == 0)
        {
            if (dp[i / 3] > dp[i] + 1)
            {
                dp[i / 3] = dp[i] + 1;
                path[i / 3] = i;
            }
        }

        if (i % 2 == 0)
        {
            if (dp[i / 2] > dp[i] + 1)
            {
                dp[i / 2] = dp[i] + 1;
                path[i / 2] = i;
            }
        }

        if (dp[i - 1] > dp[i] + 1)
        {
            dp[i - 1] = dp[i] + 1;
            path[i - 1] = i;
        }
    }

    cout << dp[1] << '\n';

    stack<int> result;
    int current = 1;
    result.push(current);

    while (current != N)
    {
        result.push(path[current]);
        current = path[current];
    }

    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }

    return 0;
}