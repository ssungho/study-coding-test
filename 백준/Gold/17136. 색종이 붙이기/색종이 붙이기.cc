#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int n{10};
const int count_part{5};

int paper[10][10]{};
int use[]{-1, 0, 0, 0, 0, 0};
int min_count = INT_MAX;

bool Check(int y, int x, int size)
{
	if (y + size > n || x + size > n)
	{
		return false;
	}

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (paper[i][j] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

void Draw(int y, int x, int size, int value)
{
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			paper[i][j] = value;
		}
	}
}

void Backtracking(int y, int x, int count)
{
	if (min_count <= count)
	{
		return;
	}

	if (x == n)
	{
		Backtracking(y + 1, 0, count);
		return;
	}

	if (y == n)
	{
		min_count = min(min_count, count);
		return;
	}

	if (paper[y][x] == 0)
	{
		Backtracking(y, x + 1, count);
		return;
	}

	for (int size = count_part; size >= 1; size--)
	{
		if (use[size] == count_part)
		{
			continue;
		}

		if (Check(y, x, size))
		{
			use[size]++;
			Draw(y, x, size, 0);
			Backtracking(y, x + size, count + 1);
			Draw(y, x, size, 1);
			use[size]--;
		}
	}
}

int main(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}

	Backtracking(0, 0, 0);

	cout << (min_count == INT_MAX ? -1 : min_count) << '\n';

	return 0;
}