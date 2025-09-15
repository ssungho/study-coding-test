#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

struct Info
{
    ull t, a, h;
};

ull n, init_atk, low, mid, high, result;
vector<Info> v;

bool Simulate(ull target)
{
    ull max_hp = target;
    ull cur_hp = target;
    ull cur_atk = init_atk;

    for (const auto &info : v)
    {
        if (info.t == 1)
        {
            ull player_atk_cnt = info.h / cur_atk;
            if (info.h % cur_atk) player_atk_cnt++;

            ull monster_atk_cnt = cur_hp / info.a;
            if (cur_hp % info.a) monster_atk_cnt++;

            if (player_atk_cnt <= monster_atk_cnt)
            {
                cur_hp -= (player_atk_cnt - 1) * info.a;
            }
            else
            {
                return false;
            }
        }
        else
        {
            cur_atk += info.a;
            cur_hp = min(cur_hp + info.h, max_hp);
        }

        if (cur_hp <= 0) return false;
    }

    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> init_atk;

    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].t >> v[i].a >> v[i].h;
    }

    low = 1;
    high = LONG_LONG_MAX;
    result = LONG_LONG_MAX;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (true == Simulate(mid))
        {
            result = min(result, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}