#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

constexpr int max_n{20};
int arr[max_n + 1][max_n + 1]{};
bool visited[max_n + 1];
int min_diff{numeric_limits<int>::max()};
int N;
vector<int> team1, team2;

int Count(vector<int> &team)
{
    int count = 0;
    int size = (int)team.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            count += arr[team[i]][team[j]];
        }
    }
    return count;
}

void DFS(int index, int count)
{
    if (count == N / 2)
    {
        team1.clear();
        team2.clear();

        for (int i = 0; i < N; i++)
        {
            if (visited[i]) team1.push_back(i);
            else team2.push_back(i);
        }

        min_diff = min(abs(Count(team1) - Count(team2)), min_diff);
        return;
    }

    for (int i = index; i < N; i++)
    {
         if (visited[i])
            continue;

        visited[i] = true;
        DFS(i + 1, count + 1);
        visited[i] = false;
    }
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    DFS(0, 0);

    cout << min_diff << '\n';

    return 0;
}