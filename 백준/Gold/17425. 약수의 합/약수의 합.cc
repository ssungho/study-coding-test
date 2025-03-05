#include <iostream>
#include <cmath>

using namespace std;

long long A[1000001]{};
long long S[1000001]{};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            A[j] += i;
        }

        if (i > 1)
        {
            S[i] = S[i - 1] + A[i];
        }
        else
        {
            S[i] = A[i];
        }
    }

    int T;
    cin >> T;

    while (T-- > 0)
    {
        int N;
        cin >> N;
        cout << S[N] << '\n';
    }

    return 0;
}