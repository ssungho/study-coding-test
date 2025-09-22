#include <bits/stdc++.h>

using namespace std;

const int max_cnt = 6;
int k, arr[49], combi[max_cnt];

void go(int next, int cnt)
{
	if (cnt == max_cnt)
	{
		for (int i = 0; i < max_cnt; i++)
		{
			cout << combi[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = next; i < k; i++)
	{
		combi[cnt] = arr[i];
		go(i + 1, cnt + 1);
	}
}

int main(void)
{
	while (true)
	{
		cin >> k;

		if (k == 0)
		{
			break;
		}

		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}

		sort(arr, arr + k);
		go(0, 0);
		cout << '\n';
	}

	return 0;
}