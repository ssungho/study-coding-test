#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M, min_distance = INT_MAX;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<pair<int, int>> picks;

int GetDistance()
{
    int total_distance = 0;

    for (auto &house_pos : houses)
    {
        int min_dist = INT_MAX;
        for (auto &pick_pos : picks)
        {
            int dist = abs(house_pos.first - pick_pos.first) + abs(house_pos.second - pick_pos.second);
            min_dist = min(min_dist, dist);
        }
        total_distance += min_dist;
    }

    return total_distance;
}

void Backtracking(int index, int pick)
{
    if (pick == M)
    {
        min_distance = min(min_distance, GetDistance());
        return;
    }

    for (int i = index; i < chickens.size(); i++)
    {
        int row = chickens[i].first;
        int col = chickens[i].second;

        picks.push_back({row, col});

        Backtracking(i + 1, pick + 1);

        picks.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 2)
            {
                chickens.push_back({i, j});
            }
            else if (map[i][j] == 1)
            {
                houses.push_back({i, j});
            }
        }
    }

    Backtracking(0, 0);

    cout << min_distance;

    return 0;
}