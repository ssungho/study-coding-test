#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &x, pair<int, int> &y)
{
    // 비트에 포함된 1의 수가 같으면 원 수가 큰것이 앞으로
    if (x.first == y.first)
        return x.second > y.second;

    return x.first > y.first;
}

int main()
{
    // 1의 개수를 기준으로 내림차순 1의 개수가 같다면 원래 10진수 기준
    vector<pair<int, int>> v;
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back({bitset<21>(temp).count(), temp});
    }
    sort(v.begin(), v.end(), compare);

    cout << v[K - 1].second;
    return 0;
}