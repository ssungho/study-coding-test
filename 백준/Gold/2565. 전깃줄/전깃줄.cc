#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<pair<int, int>> graph;

    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        graph.push_back({A, B});
    }

    sort(graph.begin(), graph.end());

    vector<int> dp(N, 1);

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (graph[j].second < graph[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << N - *max_element(dp.begin(), dp.end());

    return 0;
}