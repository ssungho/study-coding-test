#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Pos { ll x, y; };
int n;
double result;

ll cross(const Pos& center, const Pos& p1, const Pos& p2)
{
	ll ret;
	ret = center.x * p1.y + p1.x * p2.y + p2.x * center.y - (p1.x * center.y + p2.x * p1.y + center.x * p2.y);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<Pos> v(n);
	for (auto& pos : v)
	{
		cin >> pos.x >> pos.y;
	}

	for (int i = 2; i < n; i++)
	{
		result += cross(v[0], v[i - 1], v[i]) / 2.0;
	}

	cout.precision(1);
	cout << fixed << abs(result);

	return 0;
}