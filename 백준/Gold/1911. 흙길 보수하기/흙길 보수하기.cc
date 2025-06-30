#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    int N, L;
    cin >> N >> L;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int count = 0;
    int check_point = 0;

    for (auto& p : v)
    {
        int start = p.first;
        int end = p.second;

        while (start < check_point && start < end)
            start++;

        if (start >= end)
            continue;

        while (start < end)
        {
            ++count;
            int copy_start = start;
            for (int i = 0; i < L; i++)
            {
                start++;
                check_point = start;
            }
        }
    }

    cout << count << '\n';

    return 0;
}