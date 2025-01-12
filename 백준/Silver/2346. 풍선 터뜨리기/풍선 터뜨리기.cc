
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;

    deque<pair<int, int>> dq;

    for (int i = 0; i < n; ++i)
    {
        int balloon;
        cin >> balloon;

        dq.push_back({i + 1, balloon});
    }

    while (!dq.empty())
    {
        pair<int, int> cur = dq.front();
        cout << cur.first << " ";
        dq.pop_front();

        if (dq.size() == 1)
        {
            cout << dq.front().first;
            return 0;
        }

        if (cur.second > 0)
        {
            int cnt = cur.second - 1;

            for (int i = 0; i < cnt; ++i)
            {
                pair<int, int> temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
        }
        else
        {
            int cnt = -cur.second;
            for (int i = 0; i < cnt; ++i)
            {
                pair<int, int> temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
        }
    }

    return 0;
}