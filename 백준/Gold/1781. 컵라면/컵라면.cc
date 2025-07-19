#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (auto& p : v) {
        cin >> p.first >> p.second;
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    int result = 0;

    for (auto& p : v) {
        result += p.second;
        pq.push(p.second);
        if (p.first < (int)pq.size()) {
            result -= pq.top();
            pq.pop();
        }
    }

    cout << result << '\n';

    return 0;
}