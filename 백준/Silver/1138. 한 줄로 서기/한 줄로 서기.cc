#include <bits/stdc++.h>
using namespace std;

int n, arr[10], answer[10];

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	memset(answer, -1, sizeof(answer));
	for (int i = 0; i < n; i++)
	{
		int target_cnt = arr[i];
		int left_cnt = 0;
		int pos = 0;
		
		while (true)
		{
			if (answer[pos] == -1)
			{
				if (left_cnt == target_cnt)
				{
					answer[pos] = i + 1;
					break;
				}
				left_cnt++;
			}
			pos++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << ' ';
	}
	cout << '\n';

	return 0;
}