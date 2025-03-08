#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> v(100001, INT_MAX);
    v[N] = 0;

    deque<pair<int, int>> dq;
    dq.push_front({N, 0});

    while (!dq.empty())
    {
        pair<int, int> front = dq.front();

        int pos = front.first;
        int time = front.second;

        dq.pop_front();

        if (pos * 2 <= 100000 && v[pos * 2] > time)
        {
            v[pos * 2] = time;
            dq.push_front({pos * 2, time});
        }

        if (pos + 1 <= 100000 && v[pos + 1] > time + 1)
        {
            v[pos + 1] = time + 1;
            dq.push_back({pos + 1, time + 1});
        }

        if (pos - 1 >= 0 && v[pos - 1] > time + 1)
        {
            v[pos - 1] = time + 1;
            dq.push_back({pos - 1, time + 1});
        }
    }

    cout << v[K];

    return 0;
}