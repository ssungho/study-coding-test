#include <iostream>
using namespace std;

int main(void)
{
    int price[1001];
    int memo[1001];

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> price[i];
    }

    memo[1] = price[1];

    for (int i = 2; i <= N; i++)
    {
        memo[i] = price[i];
        for (int j = 1; j < i; j++)
        {
            memo[i] = min(memo[i], memo[j] + memo[i - j]);
        }
    }

    cout << memo[N];

    return 0;
}