#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_N{41};

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> vip(M);
    for (int i = 0; i < M; i++)
    {
        cin >> vip[i];
    }

    int dp[MAX_N] = { 1, 1, };

    for (int i = 2; i < MAX_N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = 1;
    int vip_index = 0;
    int count = 0;

    for (int i = 1; i <= N; i++)
    {
        if (M != 0 && i == vip[vip_index])
        {
            result *= dp[count];
            count = 0;
            vip_index++;
        }
        else
            count++;
    }

    if (count > 1)
    {
        result *= dp[count];
    }

    cout << result;

    return 0;
}