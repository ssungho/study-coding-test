#include <iostream>
#include <queue>

using namespace std;

constexpr int max_size{100001};
int n, k;
int min_count;
pair<bool, int> visited[max_size] {};

int main(void) {
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = {true, -1};

    while (!q.empty()) {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (pos == k) {
            min_count = cnt;
            break;
        }

        int next_cnt = cnt + 1;
        for (int next_pos : { pos + 1, pos - 1, pos * 2}) {
            if (0 <= next_pos && next_pos < max_size) {
                if (!visited[next_pos].first) {
                    q.push({next_pos, next_cnt});
                    visited[next_pos] = { true, pos };
                }
            }
        }
    }

    int path = k;
    vector<int> v;    
    while (path != -1) {
        v.push_back(path);
        path = visited[path].second;
    }
    
    cout << min_count << '\n';

    while (v.size())
    {
        cout << v.back() << ' ';
        v.pop_back();
    }

    return 0;
}