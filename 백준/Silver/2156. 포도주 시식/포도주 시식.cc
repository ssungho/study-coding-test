#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int> memo(n + 1, 0);

    memo[1] = v[1];
    memo[2] = v[1] + v[2];

    for (int i = 3; i <= n; i++)
    {
        int case1, case2, case3;
        case1 = memo[i - 1];
        case2 = memo[i - 2] + v[i];
        case3 = memo[i - 3] + v[i] + v[i - 1];
        memo[i] = max(case1, max(case2, case3));
    }

    cout << memo[n];

    return 0;
}