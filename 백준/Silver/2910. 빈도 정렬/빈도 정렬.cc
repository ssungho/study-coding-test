#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    if (a.second.first == b.second.first)
        return a.second.second <= b.second.second;
    return a.second.first > b.second.first;
}

int main(void)
{
    int N, C;

    cin >> N >> C;

    vector<pair<int, pair<int, int>>> v;
    map<int, pair<int, int>> m;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        if (m.end() != m.find(temp))
        {
            m[temp].first++;
        }
        else
        {
            m.insert({temp, {1, i}});
        }
    }

    for (auto &iter : m)
    {
        v.push_back(iter);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < C; i++)
    {
        if (v[i].second.first == 0)
            break;
        pair<int, pair<int, int>> &temp = v[i];
        for (int j = 0; j < temp.second.first; j++)
        {
            cout << temp.first << " ";
        }
    }

    return 0;
}