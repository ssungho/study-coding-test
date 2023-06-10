#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	// 2차원 벡터 A와 2차원 벡터 D선언 (D = 합배열)
	vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> D(N + 1, vector<int>(N + 1, 0));

	// A, D 채우기
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++) 
		{
			cin >> A[i][j];
			D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
		}
	}

	int x1, y1, x2, y2;

	// 출력
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1] << '\n';
	}

	return 0;
}