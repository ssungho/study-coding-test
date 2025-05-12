#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;

    size_t size1 = s1.size();
    size_t size2 = s2.size();

    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    int max_length = 0;
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                max_length = max(dp[i + 1][j + 1], max_length);
            }
        }
    }

    cout << max_length;

    return 0;
}