#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<int> parent;
vector<vector<int>> islands;

int find(int num)
{
    if (parent[num] != num)
        parent[num] = find(parent[num]);
    return parent[num];
}

void unionFunc(int a, int b)
{
    int fa = find(a);
    int fb = find(b);

    if (fa < fb)
        parent[fb] = fa;
    else if (fa > fb)
        parent[fa] = fb;
}

int main()
{
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        parent[i] = i;
    
    islands.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        islands[a][b] = 1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (islands[i][j] == 1 && islands[j][i] == 1)
                unionFunc(i, j);

    set<int> union_set;
    for (int i = 1; i <= n; ++i)
        union_set.insert(find(i));

    cout << union_set.size();
    return 0;
}