#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

constexpr int MAX_SIZE{1000};
constexpr int DIR_SIZE{4};
constexpr int MAX_CRASH{10};

int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};
int N{}, M{}, K{};
char map[MAX_SIZE][MAX_SIZE]{};
bool visited[MAX_SIZE][MAX_SIZE][MAX_CRASH + 1]{};

struct Node
{
    int y{}, x{}, distance{}, crash{};
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = temp[j];
        }
    }

    queue<Node> q;
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!q.empty())
    {
        Node front = q.front();
        q.pop();

        if (front.y == N - 1 && front.x == M - 1)
        {
            cout << front.distance;
            return 0;
        }

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = front.y + dy[i];
            int nx = front.x + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M)
            {
                if (!visited[ny][nx][front.crash] && map[ny][nx] == '0')
                {
                    q.push({ny, nx, front.distance + 1, front.crash});
                    visited[ny][nx][front.crash] = true;
                }
                else if (front.crash < K && !visited[ny][nx][front.crash + 1] && map[ny][nx] == '1')
                {
                    q.push({ny, nx, front.distance + 1, front.crash + 1});
                    visited[ny][nx][front.crash + 1] = true;
                }
            }
        }
    }

    cout << -1;

    return 0;
}