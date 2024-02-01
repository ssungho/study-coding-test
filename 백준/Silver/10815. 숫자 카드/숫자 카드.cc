#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        if (s.find(num) != s.end())
            cout << "1 ";
        else
            cout << "0 ";
    }

    return 0;
}