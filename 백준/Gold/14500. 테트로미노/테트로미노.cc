#include <iostream>
#include <vector>

using namespace std;

int CheckShape1(vector<vector<int>>& graph, int y, int x)
{
    int max_sum1 = 0;
    int max_sum2 = 0;

    if (x + 3 < graph[0].size())
    {
        for (int i = 0; i < 4; i++)
        {
            max_sum1 += graph[y][x + i];
        }
    }

    if (y + 3 < graph.size())
    {
        for (int i = 0; i < 4; i++)
        {
            max_sum2 += graph[y + i][x];
        }
    }

    return max(max_sum1, max_sum2);
}

int CheckShape2(vector<vector<int>>& graph, int y, int x)
{
    int sum = 0;

    if (y + 1 < graph.size() && x + 1 < graph[0].size())
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += graph[y + i][x + j];
            }
        }
    }

    return sum;
}

int CheckShape3(vector<vector<int>>& graph, int y, int x)
{
    int max_sum = 0;

    if (y + 2 < graph.size() && x + 1 < graph[0].size())
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += graph[y + i][x + j];
            }
        }

        max_sum = max(max_sum, sum - (graph[y][x] + graph[y + 1][x]));
        max_sum = max(max_sum, sum - (graph[y + 1][x] + graph[y + 2][x]));
        max_sum = max(max_sum, sum - (graph[y][x + 1] + graph[y + 1][x + 1]));
        max_sum = max(max_sum, sum - (graph[y + 1][x + 1] + graph[y + 2][x + 1]));
    }

    if (y + 1 < graph.size() && x + 2 < graph[0].size())
    {
        int sum = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum += graph[y + i][x + j];
            }
        }

        max_sum = max(max_sum, sum - (graph[y][x] + graph[y][x + 1]));
        max_sum = max(max_sum, sum - (graph[y][x + 1] + graph[y][x + 2]));
        max_sum = max(max_sum, sum - (graph[y + 1][x] + graph[y + 1][x + 1]));
        max_sum = max(max_sum, sum - (graph[y + 1][x + 1] + graph[y + 1][x + 2]));
    }

    return max_sum;
}

int CheckShape4(vector<vector<int>>& graph, int y, int x)
{
    int max_sum = 0;

    if (y + 2 < graph.size() && x + 1 < graph[0].size())
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += graph[y + i][x + j];
            }
        }

        max_sum = max(max_sum, sum - (graph[y][x] + graph[y + 2][x + 1]));
        max_sum = max(max_sum, sum - (graph[y][x + 1] + graph[y + 2][x]));
    }

    if (y + 1 < graph.size() && x + 2 < graph[0].size())
    {
        int sum = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum += graph[y + i][x + j];
            }
        }

        max_sum = max(max_sum, sum - (graph[y][x] + graph[y + 1][x + 2]));
        max_sum = max(max_sum, sum - (graph[y + 1][x] + graph[y][x + 2]));
    }

    return max_sum;
}

int CheckShape5(vector<vector<int>>& graph, int y, int x)
{
    int max_sum = 0;

    if (y + 2 < graph.size() && x + 1 < graph[0].size())
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += graph[y + i][x + j];
            }
        }

        max_sum = max(max_sum, sum - (graph[y][x] + graph[y + 2][x]));
        max_sum = max(max_sum, sum - (graph[y][x + 1] + graph[y + 2][x + 1]));
    }

    if (y + 1 < graph.size() && x + 2 < graph[0].size())
    {
        int sum = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum += graph[y + i][x + j];
            }
        }

        max_sum = max(max_sum, sum - (graph[y][x] + graph[y][x + 2]));
        max_sum = max(max_sum, sum - (graph[y + 1][x] + graph[y + 1][x + 2]));
    }

    return max_sum;
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    int max_sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        {
            max_sum = max(max_sum, 
                max(CheckShape1(graph, i, j), 
                max(CheckShape2(graph, i, j),
                max(CheckShape3(graph, i, j), 
                max(CheckShape4(graph, i, j), 
                    CheckShape5(graph, i, j))))));
        }
    }

    cout << max_sum;

    return 0;
}