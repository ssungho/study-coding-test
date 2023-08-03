#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/10942
// boj 10942 팰린드롬?

int arr[2001]; // 주어진 수열
int memo[2001][2001]; // 2차원 dp table

// 주어진 S, E가 팰린드롬인지 확인
int Check(int S, int E)
{
    // 값이 저장되어 있다면 그대로 반환
    if(memo[S][E] != -1)
        return memo[S][E];

    // 주어진 범위가 1칸 미만이거나 2칸이면 1 반환 (base)
    if(E - S <= 0)
        return memo[S][E] = 1;

    // arr[S]와 arr[E]가 다를 경우 0을 반환.
    if (arr[S] != arr[E])
        return memo[S][E] = 0;

    // S와 E사이가 팰리늗롬이라면 S와 E도 팰린드롬이다. 즉 1 반환
    if(memo[S + 1][E - 1] == 1)
        return memo[S][E] = 1;

    // arr[S]와 arr[E]가 팰린드롬인지 확인하려면 사이의 범위가 팰린드롬인지 확인하면 된다
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
        for (int j = 1; j < n + 1; j++)
            memo[i][j] = -1;
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << Check(s, e) << '\n';
    }

    return 0;
}