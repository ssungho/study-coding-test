#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//! 훔칠 수 있는 보석의 최대 가격, 보석은 한 가방에 한개, 무게 제한 있음.
//todo 무게 기준으로 정렬, 가격 기준으로 정렬.
//todo 큐에 현재 가격을 기준으로 넣자.
//todo 큐에 넣으려면 현재 무게까지. 무게는 오름차순이니까 넣을 수 있을것임.

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> v(n);
    vector<int> w(k);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> w[i];
    }

    sort(v.begin(), v.end(), [&](auto a, auto b)->bool {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    sort(w.begin(), w.end());

    long long sum = 0;
    int index = 0;

    priority_queue<int> pq;

    for (int i = 0; i < k; i++) {
        while (index < v.size() && v[index].first <= w[i]) {
            pq.push(v[index].second);
            index++;
        }

        if (pq.empty() == false) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << '\n';

    return 0;
}