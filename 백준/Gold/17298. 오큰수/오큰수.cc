#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    vector<int> result(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    stack<int> s;

    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            result[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}