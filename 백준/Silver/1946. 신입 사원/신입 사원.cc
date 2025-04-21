#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end());

        int compare = v[0].second;
        int count = 1;

        for (int i = 1; i < N; i++)
        {
            if (v[i].second < compare)
            {
                count++;
                compare = v[i].second;
            }
        }

        cout << count << '\n';
    }

    return 0;
}