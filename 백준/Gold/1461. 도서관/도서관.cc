#include <bits/stdc++.h>
using namespace std;

int n, m, pos, neg_index, pos_index, neg_max, pos_max, result;
vector<int> positives, negatives;

int main(void)
{
	cin >> n >> m;
	positives.reserve(n);
	negatives.reserve(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> pos;
		(pos > 0) ? positives.push_back(pos)
				  : negatives.push_back(-pos);
	}
	sort(positives.begin(), positives.end(), greater<>());
	sort(negatives.begin(), negatives.end(), greater<>());

	pos_index = (int)positives.size() - 1;
	for (int i = 0; i < (int)positives.size(); i += m)
	{
		result += positives[i] * 2;
		pos_index = i;
	}

	neg_index = (int)negatives.size() - 1;
	for (int i = 0; i < (int)negatives.size(); i += m)
	{
		result += negatives[i] * 2;
		neg_index = i;
	}

	if (negatives.size())
	{
		neg_max = negatives.front();
	}
	if (positives.size())
	{
		pos_max = positives.front();
	}
	result -= max(neg_max, pos_max);

	cout << result << '\n';

	return 0;
}