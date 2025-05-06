#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

constexpr int MAX_RC{50};
constexpr int MAX_CNT{251};
constexpr int MAX_DIR{4};

int dy[MAX_DIR]{-1, 1, 0, 0};
int dx[MAX_DIR]{0, 0, -1, 1};

struct Node
{
    bool isWater{};
    int count{}, y{}, x{};
};

int main(void)
{
    int R, C;
    cin >> R >> C;

    int start_y, start_x;

    vector<vector<char>> graph(R, vector<char>(C, '.'));
    queue<Node> q;
    bool visited[MAX_RC][MAX_RC][2]{};

    for (int i = 0; i < R; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < C; j++)
        {
            graph[i][j] = temp[j];

            if (graph[i][j] == 'S')
            {
                start_y = i;
                start_x = j;
                graph[i][j] = '.';
            }
            else if (graph[i][j] == '*')
            {
                q.push({true, 0, i, j});
                visited[i][j][1] = true;
            }
        }
    }

    q.push({false, 0, start_y, start_x});
    visited[start_y][start_x][0] = true;

    int min_count = MAX_CNT;

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        for (int i = 0; i < MAX_DIR; i++)
        {
            int ny = dy[i] + current.y;
            int nx = dx[i] + current.x;

            if (0 <= ny && ny < R && 0 <= nx && nx < C)
            {
                if (current.isWater)
                {
                    if (!visited[ny][nx][current.isWater] && graph[ny][nx] == '.')
                    {
                        visited[ny][nx][current.isWater] = true;
                        q.push({current.isWater, current.count + 1, ny, nx});
                    }
                }
                else
                {
                    if (!visited[ny][nx][0] && !visited[ny][nx][1])
                    {
                        if (graph[ny][nx] == '.')
                        {
                            visited[ny][nx][current.isWater] = true;
                            q.push({current.isWater, current.count + 1, ny, nx});
                        }
                        else if (graph[ny][nx] == 'D')
                        {
                            min_count = min(min_count, current.count + 1);
                        }
                    }
                }
            }
        }
    }

    if (min_count == MAX_CNT)
    {
        cout << "KAKTUS";
    }
    else
    {
        cout << min_count;
    }

    return 0;
}