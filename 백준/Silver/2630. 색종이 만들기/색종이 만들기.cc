#include <iostream>
using namespace std;

int paper[129][129];
int white = 0;
int blue = 0;

void Cut(int x, int y, int length)
{
	int count = 0;
	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + length; j++)
		{
			if (paper[i][j])
				count++;
		}
	}

	if (count == 0)
		white++;
	else if (count == length * length)
		blue++;
	else
	{
		Cut(x, y, length / 2);
		Cut(x + length / 2, y, length / 2);
		Cut(x, y + length / 2, length / 2);
		Cut(x + length / 2, y + length / 2, length / 2);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int color = 0;
			cin >> color;
			paper[i][j] = color;
		}
	}

	Cut(1, 1, n);
	cout << white << " " << blue;

	return 0;
}