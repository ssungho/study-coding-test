#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int min_diff = INT_MAX;
vector<vector<int>> abilities;
vector<bool> picked;

int GetSumScores(vector<int> &team)
{
    int sum = 0;

    for (int i = 0; i < team.size(); i++)
    {
        for (int j = 0; j < team.size(); j++)
        {
            sum += abilities[team[i]][team[j]];
        }
    }

    return sum;
}

void Backtracing(int index, vector<int> &team_start)
{
    if (team_start.size() == N / 2)
    {
        vector<int> team_link;
        for (int i = 1; i <= N; i++)
        {
            if (!picked[i])
            {
                team_link.push_back(i);
            }
        }

        min_diff = min(min_diff, abs(GetSumScores(team_start) - GetSumScores(team_link)));
    }

    for (int i = index; i <= N; i++)
    {
        if (picked[i])
            continue;

        picked[i] = true;
        team_start.push_back(i);

        Backtracing(i + 1, team_start);

        picked[i] = false;
        team_start.pop_back();
    }
}

int main(void)
{
    cin >> N;

    abilities.resize(N + 1, vector<int>(N + 1));
    picked.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> abilities[i][j];
        }
    }

    vector<int> team_start;

    Backtracing(1, team_start);

    cout << min_diff;

    return 0;
}