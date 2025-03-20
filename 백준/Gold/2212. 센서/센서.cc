#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;

    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> distances;

    for (int i = 1; i < N; i++)
    {
        distances.push_back(v[i] - v[i - 1]);
    }

    sort(distances.begin(), distances.end(), greater<int>());

    int result = 0;
    int size = distances.size();

    for (int i = K - 1; i < size; i++)
    {
        result += distances[i];
    }

    cout << result;

    return 0;
}