#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int max = INT_MIN;
    for (int i = 0; i <= N - K; i++)
    {
        int sum = 0;
        for (int j = 0; j < K; j++)
        {
            sum += v[i + j];
        }
        max = std::max(sum, max);
    }

    cout << max;

    return 0;
}