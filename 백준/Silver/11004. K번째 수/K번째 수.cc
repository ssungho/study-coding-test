#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N(0), K(0);
    vector<int> v;

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cout << v[K - 1];

    return 0;
}