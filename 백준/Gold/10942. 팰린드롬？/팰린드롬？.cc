#include <iostream>

using namespace std;
int arr[2001];
int memo[2001][2001];

int Check(int S, int E)
{
    if(memo[S][E] != -1)
        return memo[S][E];
    if(E - S <= 0 && arr[S] == arr[E])
    {
        memo[S][E] = 1;
        return memo[S][E];
    }
    if (arr[S] != arr[E])
    {
        memo[S][E] = 0;
        return memo[S][E];
    }
    if(memo[S + 1][E - 1] == 1)
        return memo[S][E] = 1;

    memo[S][E]  = Check(S + 1, E - 1);
    return memo[S][E];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            memo[i][j] = -1;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << Check(s, e) << '\n';
    }

    return 0;
}