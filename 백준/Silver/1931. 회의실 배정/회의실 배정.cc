#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &val1, pair<int, int> &val2)
{
    if(val1.second == val2.second)
        return val1.first < val2.first;

    return val1.second < val2.second;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count, start, end;
    vector<pair<int, int>> v;

    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), cmp);

    int index = 0;
    int next = 0;
    int list = 0;
    while (index < count)
    {
        if (next <= v[index].first)
        {
            next = v[index].second;
            list++;
        }
        index++;
    }

    cout << list;

    return 0;
}