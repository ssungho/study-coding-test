#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N + 1);
    vector<int> degree(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        degree[B]++;
        v[A].push_back(B);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int current = pq.top();
        cout << current << " ";
        pq.pop();

        for (auto i : v[current])
        {
            degree[i]--;
            
            if (degree[i] == 0)
            {
                pq.push(i);
            }
        }
    }

    return 0;
}