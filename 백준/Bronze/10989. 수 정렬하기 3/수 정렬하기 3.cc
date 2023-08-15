#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int memo[10001];
    for(int i = 1; i < 10001; i++)
        memo[i] = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        memo[temp]++;
    }

    for (int i = 1; i < 10001; i++)
        if (memo[i] != 0)
            for (int j = 0; j < memo[i]; j++)
                cout << i << '\n';

    return 0;
}