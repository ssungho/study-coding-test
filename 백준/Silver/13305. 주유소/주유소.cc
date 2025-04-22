#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> road(N - 1);
    vector<int> cost(N);

    for (int i = 0; i < N - 1; i++)
    {
        cin >> road[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }

    long long total = 0;
    int min_cost = cost[0];

    for (int i = 0; i < N - 1; i++)
    {
        if (cost[i] < min_cost)
        {
            min_cost = cost[i];
        }
        
        total += min_cost * road[i];
    }

    cout << total;
}