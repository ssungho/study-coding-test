#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) 
{
    string str1, str2;
    cin >> str1 >> str2;

    int size1, size2;
    size1 = (int)str1.size();
    size2 = (int)str2.size();

    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    for (int i = 0; i < size1; i++) 
    {
        for (int j = 0; j < size2; j++)
        {
            if (str1[i] == str2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    string result = "";
    int i = size1, j = size2;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            result = str1[i - 1] + result; 
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--; 
        else
            j--; 
    }

    cout << dp[size1][size2] << '\n' << result;

    return 0;
}