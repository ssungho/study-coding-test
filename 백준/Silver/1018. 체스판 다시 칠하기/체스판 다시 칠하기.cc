#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string wb[8]{ "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW" };
	string bw[8]{ "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB" };

	int n, m;
	cin >> n >> m;

	vector<string> board;
	string temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		board.push_back(temp);
	}

	vector<int> matched;
	int max_matched = 0;
	int cnt_wb;
	int cnt_bw;

	for (int i = 0; i + 7 < n; i++)
	{
		for (int j = 0; j + 7 < m; j++)
		{
			cnt_wb = 0;
			cnt_bw = 0;

			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (board[k + i][l + j] == wb[k][l])
						cnt_wb++;
					if (board[k + i][l + j] == bw[k][l])
						cnt_bw++;
				}
			}
			max_matched = min(cnt_wb, cnt_bw);
			matched.push_back(max_matched);
		}
	}

	cout << *min_element(matched.begin(), matched.end());
	return 0;
}