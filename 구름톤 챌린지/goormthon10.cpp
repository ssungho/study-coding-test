#include <iostream>
#include <string>
#include <memory.h>
#include <map>
using namespace std;

string board[202][202];
bool visited[202][202];
int Move(pair<int, int> pos, int N)
{
    memset(visited, false, sizeof(visited));
    
    map<char, pair<int, int>> yx_dir;
    yx_dir['U'] = {-1, 0};
    yx_dir['D'] = {1, 0};
    yx_dir['R'] = {0, 1};
    yx_dir['L'] = {0, -1};

    int point = 1;
    int y = pos.first;
    int x = pos.second;
    visited[y][x] = true;

    while (true)
    {
        int ny = y;
        int nx = x;
        int move = stoi(board[ny][nx].substr(0, board[ny][nx].length() - 1));
        pair<int, int> dir = yx_dir[board[ny][nx][board[ny][nx].length() - 1]];

        for (int i = 0; i < move; i++)
        {
            ny += dir.first;
            nx += dir.second;

            if (ny < 1)
                ny = N;
            else if (ny > N)
                ny = 1;
            if (nx < 1)
                nx = N;
            else if (nx > N)
                nx = 1;

            if (visited[ny][nx] == true)
                return point;

            point++;
            visited[ny][nx] = true;

            if (i == move - 1)
            {
                y = ny;
                x = nx;
            }
        }
    }
    return point;
}

int main(void)
{
    int N;
    cin >> N;

    pair<int, int> goorm;
    pair<int, int> player;

    int x, y;
    cin >> x >> y;
    goorm = {x, y};

    cin >> x >> y;
    player = {x, y};

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            string temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }

    int goorm_point = Move(goorm, N);
    int player_point = Move(player, N);

    if (player_point > goorm_point)
        cout << "player " << player_point;
    else
        cout << "goorm " << goorm_point;

    return 0;
}