#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    vector<int> IS(N, 1);
    vector<int> DS(N, 1);

    for (int i = 1; i < N; i++)
    {
        if (v[i] >= v[i - 1])
        {
            IS[i] = IS[i - 1] + 1;
        }

        if (v[i] <= v[i - 1])
        {
            DS[i] = DS[i - 1] + 1;
        }
    }

    int result = max(*max_element(IS.begin(), IS.end()), *max_element(DS.begin(), DS.end()));

    cout << result;

    return 0;
}