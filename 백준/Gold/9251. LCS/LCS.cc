#include <iostream>
#include <string>
#include <vector>

using namespace std;

int memo[1001][1001]{};

int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
                memo[i + 1][j + 1] = memo[i][j] + 1;
            else
                memo[i + 1][j + 1] = max(memo[i + 1][j], memo[i][j + 1]);
        }
    }

    cout << memo[str1.size()][str2.size()];

    return 0;
}