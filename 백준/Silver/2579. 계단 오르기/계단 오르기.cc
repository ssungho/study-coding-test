#include <iostream>
#include <algorithm>
using namespace std;

int memo[301];
int stair[301];
int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        int temp;
        cin >> temp;
        stair[i] = temp;
    }
    memo[1] = stair[1];
    memo[2] = stair[1] + stair[2];
    memo[3] = max(stair[1], stair[2]) + stair[3];

    for (int i = 4; i < n + 1; i++)
    {
        memo[i] = max(memo[i - 3] + stair[i - 1], memo[i - 2]) + stair[i];
    }

    cout << memo[n];
    return 0;
}