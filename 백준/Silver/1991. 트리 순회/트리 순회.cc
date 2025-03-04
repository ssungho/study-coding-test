#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(26);

void Preorder(int start)
{
    if (start == '.' - 65)
        return;

    vector<int> &current = v[start];

    if (current.empty())
        return;

    cout << (char)(start + 65);

    Preorder(current[0]);
    Preorder(current[1]);
}

void Inorder(int start)
{
    if (start == '.' - 65)
        return;

    vector<int> &current = v[start];

    if (current.empty())
        return;

    Inorder(current[0]);
    cout << (char)(start + 65);
    Inorder(current[1]);
}

void Postorder(int start)
{
    if (start == '.' - 65)
        return;

    vector<int> &current = v[start];

    if (current.empty())
        return;

    Postorder(current[0]);
    Postorder(current[1]);
    cout << (char)(start + 65);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char node;
        cin >> node;

        int index = node - 65;

        char left, right;
        cin >> left >> right;

        v[index].push_back(left - 65);
        v[index].push_back(right - 65);
    }

    int root = int('A' - 65);

    Preorder(root);
    cout << '\n';
    Inorder(root);
    cout << '\n';
    Postorder(root);

    return 0;
}