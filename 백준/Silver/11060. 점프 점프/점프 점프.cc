#include <iostream>
#include <algorithm>
using namespace std;

int miro[1001];
int memo[1001];

int Move(int x)
{
    memo[1] = 0;
    for (int i = 2; i < x + 1; i++)
    {
        memo[i] = INT16_MAX;
        for(int j = 1; j < i; j++) // 이전까지 값을 확인
        {
            if(miro[j] >= i - j)
                memo[i] = min(memo[i], memo[j] + 1);
        }
    }
    return memo[x];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        int number;
        cin >> number;
        miro[i] = number;
    }

    int answer = Move(n);

    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    if(miro[1] == 0)
    {
        cout << -1;
        return 0;
    }

    if(answer == INT16_MAX)
        cout << -1;
    else
        cout << answer;

    return 0;
}