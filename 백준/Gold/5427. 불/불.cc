#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{0, 0, 1, -1};
int dx[DIR_SIZE]{1, -1, 0, 0};
int w, h;

struct Info
{
    int y{}, x{}, cnt{};
};

int BFS(vector<vector<char>> &graph, vector<pair<int, int>> &fire_pos, int start_y, int start_x)
{
    int result = 0;

    vector<vector<bool>> fire_visited(h, vector<bool>(w, false));
    vector<vector<bool>> person_visited(h, vector<bool>(w, false));
    queue<Info> q;

    q.push({start_y, start_x, 0});
    person_visited[start_y][start_x] = true;

    for (size_t i = 0; i < fire_pos.size(); i++)
    {
        fire_visited[fire_pos[i].first][fire_pos[i].second] = true;
        q.push({fire_pos[i].first, fire_pos[i].second, 0});
    }

    while (!q.empty())
    {
        auto [current_y, current_x, cnt] = q.front();
        q.pop();

        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = current_y + dy[i];
            int nx = current_x + dx[i];
            char current = graph[current_y][current_x]; 

            if (current == '@')
            {
                if (ny < 0 || ny == h || nx < 0 || nx == w)
                {
                    result = cnt + 1;
                    return result;
                }
                else if (!fire_visited[ny][nx] && !person_visited[ny][nx] && graph[ny][nx] != '#') 
                {
                    graph[ny][nx] = '@';
                    q.push({ny, nx, cnt + 1 });
                    person_visited[ny][nx] = true;
                }
            }

            else if (ny >= 0 && ny < h && nx >= 0 && nx < w && graph[ny][nx] != '#' && !fire_visited[ny][nx])
            {
                graph[ny][nx] = '*';
                q.push({ny, nx, cnt + 1});
                fire_visited[ny][nx] = true;
            }
        }
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> w >> h;

        vector<vector<char>> graph(h, vector<char>(w));

        vector<pair<int, int>> fire_pos;
        int start_y, start_x;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == '*')
                {
                    fire_pos.push_back({i, j});
                }
                else if (graph[i][j] == '@')
                {
                    start_y = i;
                    start_x = j;
                }
            }
        }

        int result = BFS(graph, fire_pos, start_y, start_x);

        if (result == 0)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cout << result << '\n';
        }
    }

    return 0;
}