#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> triangle(n);
    triangle[0].push_back(1);

    for (int i = 1; i < n; i++)
    {
        triangle[i].push_back(1);
        for (int j = 1; j < i; j++)
        {
            triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
        }
        triangle[i].push_back(1);
    }

    cout << triangle[n - 1][k - 1];

    return 0;
}