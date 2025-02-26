#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }

    sort(v.begin(), v.end());

    int x;
    cin >> x;

    int start = 0;
    int end = n - 1;
    int count = 0;

    while (start < end)
    {
        int target = v[start] + v[end];

        if (target == x)
        {
            count++;
            start++;
            end--;
        }
        else if (target > x)
            end--;
        else
            start++;
    }

    cout << count;

    return 0;
}