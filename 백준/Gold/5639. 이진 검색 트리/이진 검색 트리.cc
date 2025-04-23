#include <iostream>
#include <vector>

using namespace std;

void Postorder(vector<int> &tree, int start, int end)
{
    if (start > end)
        return;

    int root = tree[start];
    int boundary = start + 1;

    while (boundary <= end && tree[boundary] < root)
        boundary++;

    Postorder(tree, start + 1, boundary - 1);
    Postorder(tree, boundary, end);

    cout << root << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> tree;
    int value;

    while (cin >> value)
    {
        tree.push_back(value);
    }

    Postorder(tree, 0, (int)tree.size() - 1);

    return 0;
}