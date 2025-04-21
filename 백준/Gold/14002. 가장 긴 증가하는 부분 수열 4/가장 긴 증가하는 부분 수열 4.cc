#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    vector<pair<int, int>> dp(N, {1, -1});
    int max_length = 1, last_index = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && dp[j].first + 1 > dp[i].first)
            {
                dp[i].first = dp[j].first + 1;
                dp[i].second = j;
            }
        }

        if (dp[i].first > max_length)
        {
            max_length = dp[i].first;
            last_index = i;
        }
    }

    cout << max_length << '\n';

    vector<int> LIS;
    
    for (int i = last_index; i != -1; i = dp[i].second)
    {
        LIS.push_back(v[i]);
    }

    reverse(LIS.begin(), LIS.end());

    for (int val : LIS)
    {
        cout << val << " ";
    }

    return 0;
}