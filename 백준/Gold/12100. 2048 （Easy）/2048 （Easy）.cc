#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX_COUNT{5};

int answer = 0;
int N = 0;

void Merge(vector<vector<int>> &map, int dir);
void DFS(vector<vector<int>> &map, int count);

int main(void)
{
    cin >> N;

    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    DFS(map, 0);
    cout << answer;

    return 0;
}

void Merge(vector<vector<int>> &map, int dir)
{
    vector<vector<int>> new_map(N, vector<int>(N, 0));

    if (dir == 0)
    {
        for (int i = 0; i < N; i++)
        {
            queue<int> q;
            for (int y = 0; y < N; y++)
            {
                if (map[y][i] != 0)
                {
                    q.push(map[y][i]);
                }
            }

            int index = 0;
            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (!q.empty())
                {
                    if (q.front() == val)
                    {
                        val *= 2;
                        q.pop();
                    }
                }

                new_map[index][i] = val;
                index++;
            }
        }
    }

    else if (dir == 1)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            queue<int> q;
            for (int y = N - 1; y >= 0; y--)
            {
                if (map[y][i] != 0)
                {
                    q.push(map[y][i]);
                }
            }

            int index = N - 1;
            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (!q.empty())
                {
                    if (q.front() == val)
                    {
                        val *= 2;
                        q.pop();
                    }
                }

                new_map[index][i] = val;
                index--;
            }
        }
    }

    else if (dir == 2)
    {
        for (int i = 0; i < N; i++)
        {
            queue<int> q;
            for (int x = 0; x < N; x++)
            {
                if (map[i][x] != 0)
                {
                    q.push(map[i][x]);
                }
            }

            int index = 0;
            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (!q.empty())
                {
                    if (q.front() == val)
                    {
                        val *= 2;
                        q.pop();
                    }
                }

                new_map[i][index] = val;
                index++;
            }
        }
    }

    else
    {
        for (int i = N - 1; i >= 0; i--)
        {
            queue<int> q;
            for (int x = N - 1; x >= 0; x--)
            {
                if (map[i][x] != 0)
                {
                    q.push(map[i][x]);
                }
            }

            int index = N - 1;
            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (!q.empty())
                {
                    if (q.front() == val)
                    {
                        val *= 2;
                        q.pop();
                    }
                }

                new_map[i][index] = val;
                index--;
            }
        }
    }

    map = new_map;
}

void DFS(vector<vector<int>> &map, int count)
{
    if (count == MAX_COUNT)
    {
        for (int i = 0; i < N; i++)
        {
            answer = max(answer, *max_element(map[i].begin(), map[i].end()));
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        auto copy_map = map;
        Merge(copy_map, i);
        DFS(copy_map, count + 1);
    }
}