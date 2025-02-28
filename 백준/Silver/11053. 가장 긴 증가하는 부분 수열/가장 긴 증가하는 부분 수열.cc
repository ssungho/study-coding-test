#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A[1001]{};
    int memo[1001]{};

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        memo[i] = 1;
    }

    int max_cnt = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (A[i] > A[j])
            {
                memo[i] = max(memo[i],  memo[j] + 1);
                if (memo[i] > max_cnt)
                    max_cnt = memo[i];
            }
        }
    }

    cout << max_cnt;

    return 0;
}