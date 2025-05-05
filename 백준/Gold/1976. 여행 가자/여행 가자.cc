#include <iostream>
#include <vector>

using namespace std;

int Find(vector<int> &parent, int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = Find(parent, parent[a]);
}

bool Union(vector<int> &parent, int a, int b)
{
    int root_a = Find(parent, a);
    int root_b = Find(parent, b);

    if (root_a == root_b)
        return false;

    if (root_a < root_b)
        parent[root_b] = root_a;
    else
        parent[root_a] = root_b;

    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> parent(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<int> path(M + 1, 0);
    for (int i = 1; i <= M; i++)
    {
        cin >> path[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j] == 1)
            {
                Union(parent, i, j);
            }
        }
    }

    bool result = true;
    int root = Find(parent, path[1]);

    for (int i = 2; i <= M; i++)
    {
        if (Find(parent, path[i]) != root)
        {
            result = false;
            break;
        }
    }

    if (result)
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}