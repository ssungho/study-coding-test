#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Food
{
    int p, f, s, v, c;

    bool Satisfied(int _mp, int _mf, int _ms, int _mv)
    {
        return (_mp <= p && _mf <= f && _ms <= s && _mv <= v);
    }
    Food &operator+=(const Food &rhs)
    {
        p += rhs.p;
        f += rhs.f;
        s += rhs.s;
        v += rhs.v;
        c += rhs.c;
        return *this;
    }
};

int N;
int mp, mf, ms, mv;
int min_cost{INT_MAX};
vector<vector<int>> indexes;

void DfS(vector<Food> &v, vector<int> &foods, int index)
{
    Food result{};
    for (int i : foods)
    {
        result += v[i];
    }

    if (result.Satisfied(mp, mf, ms, mv))
    {
        if (min_cost > result.c)
        {
            indexes.clear();
            min_cost = result.c;
            indexes.push_back(foods);
        }
        else if (min_cost == result.c)
        {
            indexes.push_back(foods);
        }
    }

    if (index == N) 
        return;

    for (int i = index; i < N; i++)
    {
        foods.push_back(i);
        DfS(v, foods, i + 1);
        foods.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    vector<Food> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].p >> v[i].f >> v[i].s >> v[i].v >> v[i].c;
    }

    vector<int> foods;
    foods.reserve(N);
    DfS(v, foods, 0);

    if (min_cost == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        sort(indexes.begin(), indexes.end());

        cout << min_cost << '\n';
        for (int i : indexes[0])
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}