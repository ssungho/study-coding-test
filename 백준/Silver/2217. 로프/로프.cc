#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int max_weight = -1;

    for (int i = 0; i < N; i++)
    {
        int current = v[i];
        max_weight = max(max_weight, current * (i + 1));
    }

    cout << max_weight;

    return 0;
}