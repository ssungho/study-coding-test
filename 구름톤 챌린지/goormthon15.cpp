#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<pair<long long, long long>> fruits;

    int N;
    long long K;

    // 입력
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        long long price, fullness;
        cin >> price >> fullness;
        fruits.push_back({fullness / price, price});
    }
    // 정렬
    sort(fruits.begin(), fruits.end(), greater<>());

    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        long long count = min(K, fruits[i].second); // 가진 돈, 과일 개수
        sum += count * fruits[i].first;
        K -= count;

        if (K == 0)
            break;
    }

    cout << sum;
    return 0;
}