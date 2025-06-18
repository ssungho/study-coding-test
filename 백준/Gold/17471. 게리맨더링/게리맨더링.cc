#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory.h>

using namespace std;

constexpr int max_diff{2001};
constexpr int max_cities{10};
int people[max_cities + 1]{};
bool visited[max_cities + 1]{};
int N;

int DFS(vector<vector<int>> &adj_cities, int current, unordered_set<int> &cities)
{
    int count = people[current];

    for (int city : adj_cities[current])
    {
        if (visited[city])
            continue;
        if (cities.end() == cities.find(city))
            continue;

        visited[city] = true;
        count += DFS(adj_cities, city, cities);
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

    unordered_set<int> left_cities, right_cities;
    for (int i = 0; i < max_bit; i++)
    {
        memset(visited, 0, max_cities + 1);
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                left_cities.insert(j + 1);
            }
            else
            {
                right_cities.insert(j + 1);
            }
        }

        int count = 0;
        int left, right;

        for (int j = 1; j <= N; j++)
        {
            if (count > 2) 
                continue;

            if (!visited[j])
            {
                visited[j] = true;
                if (count == 0)
                {
                    left = DFS(adj_cities, j, left_cities);
                }
                else if (count == 1)
                {
                    right = DFS(adj_cities, j, right_cities);
                }
                count++;
            }
        }

        if (count == 2)
        {
            min_count = min(min_count, abs(left - right));
        }

        left_cities.clear();
        right_cities.clear();
    }

    if (min_count == max_diff) 
        min_count = -1;

    cout << min_count << '\n';

    return 0;
}