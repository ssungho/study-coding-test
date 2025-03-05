#include <iostream>
#include <cmath>

using namespace std;

long long memo[1000001]{};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < 1000001; i++)
    {
        for (int j = i; j < 1000001; j += i)
        {
            memo[j] += i;
        }

        memo[i] = memo[i - 1] + memo[i];
    }

    int T;
    cin >> T;

    while (T-- > 0)
    {
        int N;
        cin >> N;
        cout << memo[N] << '\n';
    }

    return 0;
}