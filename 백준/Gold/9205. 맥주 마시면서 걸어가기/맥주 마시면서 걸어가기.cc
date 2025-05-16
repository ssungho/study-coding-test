#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Pos = pair<int, int>;
using Node = pair<int, Pos>;
constexpr int MAX_DIST{1000};

int Find(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = Find(parent, parent[node]);
}

void Union(vector<int> &parent, int node1, int node2)
{

    int root1 = Find(parent, node1);
    int root2 = Find(parent, node2);

    if (root1 == root2)
        return;

    if (root1 < root2)
        parent[root2] = root1;
    else
        parent[root1] = root2;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        n += 2;

        vector<Pos> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        vector<int> parent(n, 0);
        for (int i = 1; i < n; i++)
        {
            parent[i] = i;
        }

        vector<Node> Linked;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(v[j].first - v[i].first) + abs(v[j].second - v[i].second);

                if (dist <= MAX_DIST)
                {
                    Linked.push_back({dist, {i, j}});
                }
            }
        }

        sort(Linked.begin(), Linked.end());

        for (auto &[dist, pos] : Linked)
        {
            Union(parent, pos.first, pos.second);
        }

        int src = parent.front();
        int dst = parent.back();

        if (Find(parent, src) == Find(parent, dst))
            cout << "happy\n";
        else
            cout << "sad\n";
    }

    return 0;
}