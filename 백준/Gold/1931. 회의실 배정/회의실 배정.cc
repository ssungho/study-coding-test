#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<int, int>> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [&](auto a, auto b) -> bool
    {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int result = 0;
    int end_time = 0;

    for (int i = 0; i < n; i++) {
        if (v[i].first >= end_time) {
            end_time = v[i].second;
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}