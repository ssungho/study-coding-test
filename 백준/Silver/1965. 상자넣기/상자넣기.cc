#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> boxes(n, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> boxes[i];
    }

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (boxes[i] > boxes[j])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}