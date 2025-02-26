#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(void)
{
    // 1. 입력받은 값을 정렬한다.
    // 2. 투 포인터를 이용해서 가장 작은 값을 구한다.
    // 3. 자료형에 주의하자.

    int N;
    cin >> N;

    vector<long long> v(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = N - 1;
    pair<int, int> find;
    long long prev = LLONG_MAX;

    while (start < end)
    {
        long long target = abs(v[start] + v[end]);

        if (target < prev)
        {
            prev = target;
            find = {v[start], v[end]};
        }

        if (abs(v[start + 1] + v[end]) < abs(v[start] + v[end - 1]))
            start++;
        else
            end--;
    }

    cout << find.first << " " << find.second;

    return 0;
}