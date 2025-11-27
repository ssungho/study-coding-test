#include <bits/stdc++.h>
using namespace std;

int a[9][9];
string str_row;
vector<pair<int, int>> empty_pos;
bool finished;

bool check(int num, int row, int col)
{
	bool check_row[10]{};
	bool check_col[10]{};
	bool check_area[10]{};

	for (int i = 0; i < 9; i++)
	{
		check_row[a[row][i]] = true;
		check_col[a[i][col]] = true;
	}

	int area_row = (row / 3) * 3;
	int area_col = (col / 3) * 3;

	for (int i = area_row; i < area_row + 3; i++)
	{
		for (int j = area_col; j < area_col + 3; j++)
		{
			check_area[a[i][j]] = true;
		}
	}

	// 기록이 안되어있으면 num 사용 가능.
	return !check_row[num] && !check_col[num] && !check_area[num];
}

void go(int here)
{
	if (here == (int)empty_pos.size())
	{
		finished = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << a[i][j];
			}
			cout << '\n';
		}
		return;
	}

	int cur_row = empty_pos[here].first;
	int cur_col = empty_pos[here].second;

	for (int j = 1; j <= 9; j++)
	{
		if (check(j, cur_row, cur_col))
		{
			a[cur_row][cur_col] = j;
			go(here + 1);
			a[cur_row][cur_col] = 0;
		}

		if (finished)
		{
			return;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	for (int i = 0; i < 9; i++)
	{
		cin >> str_row;
		for (int j = 0; j < 9; j++)
		{
			a[i][j] = str_row[j] - '0';
			if (a[i][j] == 0)
			{
				empty_pos.push_back({i, j});
			}
		}
	}

	go(0);

	return 0;
}