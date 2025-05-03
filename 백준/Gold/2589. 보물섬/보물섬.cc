#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node
{
    int dist{}, y{}, x{};
};

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int H, W;

int BFS(vector<vector<char>> &map, int y, int x)
{
    int result = 0;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    queue<Node> q;
    visited[y][x] = true;
    q.push({0, y, x});

    while (!q.empty())
    {
        Node current = q.front();
        result = max(current.dist, result);
        q.pop();

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = current.y + dy[i];
            int nx = current.x + dx[i];
            if (0 <= ny && ny < H && 0 <= nx && nx < W && map[ny][nx] == 'L' && !visited[ny][nx])
            {
                q.push({current.dist + 1, ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W;
    vector<vector<char>> map(H, vector<char>(W, 'W'));

    for (int i = 0; i < H; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++)
        {
            map[i][j] = row[j];
        }
    }

    int answer = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == 'L')
            {
                answer = max(answer, BFS(map, i, j));
            }
        }
    }

    cout << answer;

    return 0;
}