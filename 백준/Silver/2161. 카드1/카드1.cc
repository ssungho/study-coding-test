#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    queue<int> q;

    for (int i = 0; i < n; i++)
        q.push(i + 1);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();

        if (!q.empty())
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    return 0;
}