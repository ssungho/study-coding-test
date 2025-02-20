#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Code
{
    int number;
    int frequency;
    int first;
};

bool compare(Code &a, Code &b)
{
    if (a.frequency == b.frequency)
        return a.first <= b.first;
    return a.frequency > b.frequency;
}

int main(void)
{
    int N, C;

    cin >> N >> C;

    vector<Code> v;
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
        v.push_back({iter.first, iter.second.first, iter.second.second});
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < C; i++)
    {
        if (v[i].frequency == 0)
            break;
        Code &temp = v[i];
        for (int j = 0; j < temp.frequency; j++)
        {
            cout << temp.number << " ";
        }
    }

    return 0;
}