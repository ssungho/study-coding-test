#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> v(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = N - 1;
    pair<int, int> find;
    long long prev = LLONG_MAX;

    while (start < end)
    {
        long long target = abs(v[start] + v[end]);

        if (target < prev)
        {
            prev = target;
            find = {v[start], v[end]};
        }

        if (abs(v[start + 1] + v[end]) < abs(v[start] + v[end - 1]))
            start++;
        else
            end--;
    }

    cout << find.first << " " << find.second;

    return 0;
}