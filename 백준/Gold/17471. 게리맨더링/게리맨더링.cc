#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory.h>

using namespace std;

constexpr int max_diff{2001};
constexpr int max_cities{10};
int people[max_cities + 1]{};
bool visited[max_cities + 1]{};
bool in_left[max_cities + 1]{};
int N;

int DFS(vector<vector<int>> &adj_cities, int current, bool check_left)
{
    visited[current] = true;
    int count = people[current];

    for (int city : adj_cities[current])
    {
        if (visited[city])
            continue;
        if (check_left && !in_left[city])
            continue;
        if (!check_left && in_left[city])
            continue;

        visited[city] = true;
        count += DFS(adj_cities, city, check_left);
    }

    return count;
}

int main(void)
{
    cin >> N;

    vector<vector<int>> adj_cities(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> people[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int adj_count;
        cin >> adj_count;

        for (int j = 0; j < adj_count; j++)
        {
            int city;
            cin >> city;
            adj_cities[i].push_back(city);
            adj_cities[city].push_back(i);
        }
    }

    int min_count = max_diff;
    int max_bit = (1 << N);

    for (int i = 0; i < max_bit; i++)
    {
        memset(visited, 0, max_cities + 1);
        memset(in_left, 0, max_cities + 1);

        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                in_left[j + 1] = true;
            }
        }

        int count = 0;
        int left, right;

        for (int j = 1; j <= N; j++)
        {
            if (!visited[j])
            {
                if (count == 0)
                {
                    left = DFS(adj_cities, j, true);
                }
                else if (count == 1)
                {
                    right = DFS(adj_cities, j, false);
                }
                count++;
            }

            if (count > 2)
            {
                break;
            }
        }

        if (count == 2)
        {
            min_count = min(min_count, abs(left - right));
        }
    }

    if (min_count == max_diff)
    {
        min_count = -1;
    }

    cout << min_count << '\n';

    return 0;
}