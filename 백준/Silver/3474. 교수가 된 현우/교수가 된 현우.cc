#include <bits/stdc++.h>
using namespace std;

long long t, n, answer;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> n;
        answer = 0;

        for (int i = 5; i <= n; i *= 5)
        {
            answer += n / i;
        }
        
        cout << answer << '\n';
    }

    return 0;
}