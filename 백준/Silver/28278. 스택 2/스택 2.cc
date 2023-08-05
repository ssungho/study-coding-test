#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;

        if (number == 1)
        {
            cin >> number;
            v.push_back(number);
        }
        else if (number == 2)
        {
            if (v.empty())
                cout << -1 << '\n';
            else
            {
                cout << v.back() << '\n';
                v.pop_back();
            }
        }
        else if (number == 3)
        {
            cout << v.size() << '\n';
        }
        else if (number == 4)
        {
            if (v.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            if (v.empty())
                cout << -1 << '\n';
            else
                cout << v.back() << '\n';
        }
    }

    return 0;
}