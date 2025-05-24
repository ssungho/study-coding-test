#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
using pair_ll = pair<ll, ll>;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<pair_ll, vector<pair_ll>, greater<pair_ll>> times;

    for (int i = 0; i < N; i++)
    {
        ll S, T;
        cin >> S >> T;
        times.push({S, T});
    }
    
    priority_queue<ll, vector<ll>, greater<ll>> end;
    end.push(times.top().second);
    times.pop();
    int count = 1;

    while (!times.empty()) 
    {
        pair_ll time = times.top();
        times.pop();

        if (end.top() <= time.first)
            end.pop();

        end.push(time.second);
        count = max(count, (int)end.size());
    }

    cout << count;

    return 0;
}