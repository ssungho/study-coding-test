#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    vector<int> v(N + 1, 0);
    vector<long long> a(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];

        if (v[i] == S)
        {
            cout << 1;
            return 0;
        }
       
        a[i] = a[i - 1] + v[i];
    }

    int length = INT_MAX;
    int start = 0, end = 0;

    while (end <= N)
    {
        while (a[end] - a[start] >= S && start < end)
        {
            length = min(length, end - start);
            start++;
        }

        end++;
    }

    if (length == INT_MAX)
        cout << 0;
    else
        cout << length;

    return 0;
}