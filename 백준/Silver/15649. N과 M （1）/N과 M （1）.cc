#include <bits/stdc++.h>

using namespace std;

vector<int> v;
bool visited[9];
int n, m;

void go(int cur, int cnt)
{
    if (cnt == m)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(i);
            go(i + 1, cnt + 1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> n >> m;

    go(1, 0);

    return 0;
}