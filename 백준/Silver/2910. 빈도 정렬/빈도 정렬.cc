#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, C;
    cin >> N >> C;

    map<int, pair<int, int>> m;
    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;

        if (m.find(number) != m.end())
        {
            m[number].first++;
        }
        else
        {
            m.insert({number, {1, i}});
        }
    }

    vector<pair<int, pair<int, int>>> v(N);
    int index = 0;
    for (auto &ele : m)
    {
        v[index++] = ele;
    }

    sort(v.begin(), v.end(), [&](auto &left, auto &right) -> bool 
    {
        if (left.second.first == right.second.first) 
        {
            return left.second.second < right.second.second;
        }

        return left.second.first > right.second.first; 
    });

    for (auto &ele : v)
    {
        for (int i = 0; i < ele.second.first; i++)
            cout << ele.first << " ";
    }

    return 0;
}