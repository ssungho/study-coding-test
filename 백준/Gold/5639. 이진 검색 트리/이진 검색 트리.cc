#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int value{};
    Node *left{nullptr};
    Node *right{nullptr};

    void Postorder()
    {
        if (left) left->Postorder();
        if (right) right->Postorder();
        cout << value << '\n';
    }

    ~Node()
    {
        if (left) delete left;
        if (right) delete right;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node *root_node = new Node();
    cin >> root_node->value;

    int value;
    while (cin >> value)
    {
        Node *current = root_node;
        Node *prev = nullptr;
        while (current)
        {
            prev = current;
            if (current->value > value)
                current = current->left;
            else
                current = current->right;
        }

        current = new Node{value, nullptr, nullptr};

        if (prev->value < value)
            prev->right = current;
        else
            prev->left = current;
    }

    root_node->Postorder();

    delete root_node;

    return 0;
}