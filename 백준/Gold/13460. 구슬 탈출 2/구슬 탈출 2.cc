#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_SIZE{10};
constexpr int DIR_SIZE{4};

char board[MAX_SIZE][MAX_SIZE]{};
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE]{};

int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};

int N, M;

struct BeadPos
{
    int red_y{}, red_x{}, blue_y{}, blue_x{};
};

int BFS(const BeadPos &pos)
{
    queue<pair<BeadPos, int>> q;
    q.push({pos, 0});

    int min_count = 11;

    while (!q.empty())
    {
        BeadPos current = q.front().first;
        int current_count = q.front().second;
        q.pop();

        BeadPos next = current;

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int red_move = 0;
            int blue_move = 0;
            bool is_red_reached = false;
            bool is_blue_reached = false;

            while (true)
            {
                int ny = dy[i] * red_move + current.red_y;
                int nx = dx[i] * red_move + current.red_x;

                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    continue;

                if (board[ny][nx] != '#')
                {
                    red_move++;
                    next.red_y = ny;
                    next.red_x = nx;

                    if (board[ny][nx] == 'O')
                    {
                        is_red_reached = true;
                        break;
                    }
                }
                else
                    break;
            }

            while (true)
            {
                int ny = dy[i] * blue_move + current.blue_y;
                int nx = dx[i] * blue_move + current.blue_x;

                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    continue;

                if (board[ny][nx] != '#')
                {
                    blue_move++;
                    next.blue_y = ny;
                    next.blue_x = nx;

                    if (board[ny][nx] == 'O')
                    {
                        is_blue_reached = true;
                        break;
                    }
                }
                else
                    break;
            }

            if (!is_red_reached && !is_blue_reached && next.red_y == next.blue_y && next.red_x == next.blue_x)
            {
                if (red_move < blue_move)
                {
                    next.blue_y -= dy[i];
                    next.blue_x -= dx[i];
                }
                else
                {
                    next.red_y -= dy[i];
                    next.red_x -= dx[i];
                }
            }
            else if (is_blue_reached)
            {
                continue;
            }
            else if (is_red_reached)
            {
                min_count = min(min_count, current_count + 1);
                continue;
            }

            if (!visited[next.red_y][next.red_x][next.blue_y][next.blue_x] && current_count + 1 < 10)
            {
                q.push({next, current_count + 1});
                visited[next.red_y][next.red_x][next.blue_y][next.blue_x] = true;
            }
        }
    }

    if (min_count == 11)
        return -1;

    return min_count;
}

int main(void)
{
    cin >> N >> M;

    BeadPos bead_pos{};
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = temp[j];
            if (board[i][j] == 'R')
            {
                bead_pos.red_y = i;
                bead_pos.red_x = j;
            }
            else if (board[i][j] == 'B')
            {
                bead_pos.blue_y = i;
                bead_pos.blue_x = j;
            }
        }
    }

    visited[bead_pos.red_y][bead_pos.red_x][bead_pos.blue_y][bead_pos.blue_x] = true;

    cout << BFS(bead_pos);

    return 0;
}