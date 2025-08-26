#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

constexpr int monster = 1;
constexpr int potion = 2;
ll n, atk;
vector<pair<ll, pair<ll, ll>>> v;

bool Check(ll target)
{
	ll max_hp = target;
	ll cur_hp = max_hp;
	ll cur_atk = atk;

	for (int i = 0; i < n; i++)
	{
		if (monster == v[i].first)
		{
			ll atk_monster = v[i].second.first;
			ll hp_monster = v[i].second.second;

			ll cnt_player_atk = hp_monster / cur_atk;
			if (hp_monster % cur_atk)
			{
				cnt_player_atk++;
			}

			ll cnt_monster_atk = cur_hp / atk_monster;
			if (cur_hp % atk_monster)
			{
				cnt_monster_atk++;
			}

			if (cnt_player_atk > cnt_monster_atk)
			{
				return false;
			}

			cur_hp -= (cnt_player_atk - 1) * atk_monster;
		}
		else
		{
			cur_atk += v[i].second.first;
			cur_hp += v[i].second.second;
			cur_hp = min(cur_hp, max_hp);
		}
	}

	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> atk;

	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		cin >> v[i].second.first;
		cin >> v[i].second.second;
	}

	ll left = 0;
	ll right = LONG_LONG_MAX;
	ll result = 0;

	while (left <= right)
	{
		ll mid = (left + right) / 2;

		if (Check(mid))
		{
			result = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}