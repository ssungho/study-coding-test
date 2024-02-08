#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);
    vector<vector<int>> memo(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int temp;
            cin >> temp;
            triangle[i].push_back(temp);
        }
    }

    memo[0] = triangle[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                memo[i].push_back(triangle[i][j] + memo[i - 1][j]);
            else if (j == i)
                memo[i].push_back(triangle[i][j] + memo[i - 1][j - 1]);
            else
                memo[i].push_back(triangle[i][j] + max(memo[i - 1][j - 1], memo[i - 1][j]));
        }
    }

    cout << *max_element(memo[n - 1].begin(), memo[n - 1].end());

    return 0;
}