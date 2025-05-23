#include <iostream>
#include <vector>
#include <deque>

using namespace std;

constexpr int EMPTY{0};
constexpr int APPLE{1};
constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 0, 1, 0};
int dx[DIR_SIZE]{0, -1, 0, 1};

typedef struct tag2D
{
    int y, x;

    tag2D operator+(const tag2D &t)
    {
        return {y + t.y, x + t.x};
    }

    bool operator==(const tag2D &t)
    {
        return ((y == t.y) && (x == t.x));
    }
} Pos, Dir;

int main(void)
{
    int N, K, L;
    cin >> N >> K;

    vector<vector<char>> graph(N + 1, vector<char>(N + 1, EMPTY));
    for (int i = 0; i < K; i++)
    {
        int row, col;
        cin >> row >> col;
        graph[row][col] = APPLE;
    }

    cin >> L;

    vector<pair<int, char>> dirs(L);
    for (int i = 0; i < L; i++)
    {
        cin >> dirs[i].first >> dirs[i].second;
    }

    int current_dir = 3;
    Pos current_pos = {1, 1};

    deque<Pos> snake_body;
    snake_body.push_front(current_pos);

    int count = 0;

    while (true)
    {
        count++;

        Dir next_dir = {dy[current_dir], dx[current_dir]};
        Pos next_pos = snake_body.front() + next_dir;

        if (next_pos.y > N || next_pos.y <= 0 ||
            next_pos.x > N || next_pos.x <= 0)
            break;

        bool isCol = false;
        for (auto &pos : snake_body)
        {
            if (pos == next_pos)
            {
                isCol = true;
                break;
            }
        }

        if (isCol)
            break;

        snake_body.push_front(next_pos);

        if (graph[next_pos.y][next_pos.x] == APPLE)
            graph[next_pos.y][next_pos.x] = EMPTY;
        else
            snake_body.pop_back();

        for (auto &dir : dirs)
        {
            if (dir.first > 0)
            {
                if (--dir.first == 0)
                {
                    if (dir.second == 'D')
                        current_dir = (current_dir + 3) % 4;
                    else
                        current_dir = (current_dir + 1) % 4;
                }
            }
        }
    }

    cout << count;

    return 0;
}