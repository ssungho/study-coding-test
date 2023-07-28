#include <iostream>
using namespace std;
int memo[1000001];

int CountTile(int x)
{
    memo[1] = 1;
    memo[2] = 2;

    for(int i = 3; i < x + 1; i++)
    {
        memo[i] = (memo[i - 1]+ memo[i - 2]) % 15746;
    }

    return memo[x];
}

int main(void)
{
    int n;
    cin >> n;

    cout << CountTile(n);

    return 0;
}