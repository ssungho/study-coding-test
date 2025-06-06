#include <iostream>
#include <vector>

using namespace std;

constexpr int ROOT{-1};

void FindLeafNode(vector<vector<int>>& tree, int current, int& count)
{
    auto& child = tree[current];

    if (child.size() == 0) 
    {
        count++;
    }
    else 
    {
        for(auto i : child)
        {
            FindLeafNode(tree, i, count);
        }
    }
}

int main(void) 
{
    int N;
    cin >> N;

    vector<vector<int>> tree(N);

    int root_node;

    for (int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;

        if (parent == ROOT)
        {
            root_node = i;
            continue;
        }

        tree[parent].push_back(i);
    }

    int remove;
    cin >> remove;

    if (remove == root_node)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (auto iter = tree[i].begin(); iter != tree[i].end();)
        {
            if (*iter == remove)
                iter = tree[i].erase(iter);
            else 
                iter++;
        }
    }

    int count = 0;
    FindLeafNode(tree, root_node, count);

    cout << count;

    return 0;
}