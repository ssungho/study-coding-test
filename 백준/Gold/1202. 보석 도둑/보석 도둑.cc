#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) 
{
    using ll = long long;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> infos(N);
    vector<ll> bags(K);
    
    for (int i = 0; i < N; i++)
    {
        cin >> infos[i].first >> infos[i].second;
    }

    for (int i = 0; i < K; i++)
    {
        cin >> bags[i];
    }

    sort(infos.begin(), infos.end());
    sort(bags.begin(), bags.end());

    priority_queue<ll> pq;
    ll result = 0;
    int info_index = 0;

    for (int i = 0; i < K; i++)
    {
        while (info_index < N && infos[info_index].first <= bags[i])
        {
            pq.push(infos[info_index].second);
            ++info_index;
        }

        if (!pq.empty()) 
        {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << '\n';

    return 0;
}