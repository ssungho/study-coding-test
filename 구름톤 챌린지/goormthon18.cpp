#include <iostream>
#include <vector>
#include <map>
using namespace std;

// y, x 선의 개수
pair<int, int> board[101][101];
int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int y, x;
        char dir;

        cin >> y >> x >> dir;
        if (dir == 'U')
        {
            for (int j = y; j > 0; j--)
                board[j][x].first++;
        }
        else if (dir == 'D')
        {
            for (int j = y; j < N + 1; j++)
                board[j][x].first++;
        }
        else if (dir == 'L')
        {
            for (int j = x; j > 0; j--)
                board[y][j].second++;
        }
        else if (dir == 'R')
        {
            for (int j = x; j < N + 1; j++)
                board[y][j].second++;
        }
    }

    // 교차점 구하기
    // 교차점은 y*x
    long answer = 0;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            answer += ((long)board[i][j].first * board[i][j].second);
        }
    }

    cout << answer;
    return 0;
}