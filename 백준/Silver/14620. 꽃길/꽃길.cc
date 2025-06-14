#include <iostream>
#include <vector>

using namespace std;

constexpr int dir_size{5};
constexpr int dy[dir_size]{0, -1, 1, 0, 0};
constexpr int dx[dir_size]{0, 0, 0, -1, 1};
constexpr int target_count{3};

int N{};
int min_cost{20000};

int Plant(vector<vector<int>>& map, vector<vector<bool>>& planted, int y, int x, bool undo)
{
    int cost = 0;
    for (int i = 0; i < dir_size; i++)
    {
        planted[y + dy[i]][x + dx[i]] = undo ? false : true;
        cost += map[y + dy[i]][x + dx[i]];
    }
    return cost;
}

bool CanPlant(vector<vector<int>>& map, vector<vector<bool>>& planted, int y, int x)
{
    for (int i = 0; i < dir_size; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!(0 <= ny && ny < N && 0 <= nx && nx < N && !planted[ny][nx]))
        {
            return false;
        }
    }

    return true;
}

void Backtracking(vector<vector<int>>& map, vector<vector<bool>>& planted, int y, int x, int cost, int count)
{
    if (count == target_count)
    {
        min_cost = min(min_cost, cost);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (CanPlant(map, planted, i, j))
            {
                Backtracking(map, planted, i + 1, j + 1, cost + Plant(map, planted, i, j, false), count + 1);
                Plant(map, planted, i, j, true);
            }
        }
    }
}

int main(void)
{
    cin >> N;

    vector<vector<int>> costs(N, vector<int>(N, 0));
    vector<vector<bool>> planted(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> costs[i][j];
        }
    }

    Backtracking(costs, planted, 0, 0, 0, 0);

    cout << min_cost << '\n';

    return 0;
}