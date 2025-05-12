#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    long long min_diff = LLONG_MAX;
    for (int i = 1; i < (1 << N); i++)
    {
        long long mul = 1;
        long long sum = 0;

        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                mul *= v[j].first;
                sum += v[j].second;
            }
        }

        long long diff = abs(mul - sum);
        min_diff = min(min_diff, diff);
    }

    cout << min_diff;

    return 0;
}