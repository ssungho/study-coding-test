#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(make_pair(temp, i));
    }

    sort(v.begin(), v.end());

    int max_count = 0;
    for (int i = 0; i < n; i++)
    {
        int count = v[i].second - i;
        if(max_count < count)
            max_count = count;
    }

    cout << max_count + 1;

    return 0;
}