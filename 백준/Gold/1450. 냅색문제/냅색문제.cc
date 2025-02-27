#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ull = unsigned long long;

void MakeSubSums(vector<ull> &arr, vector<ull> &sums, ull sum, int index)
{
    if (index == arr.size())
    {
        sums.push_back(sum);
        return;
    }

    MakeSubSums(arr, sums, sum, index + 1);
    MakeSubSums(arr, sums, sum + arr[index], index + 1);
}

int main(void)
{
    int N;
    ull C;
    cin >> N >> C;

    vector<ull> bag(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> bag[i];
    }

    int middle = N / 2;
    vector<ull> left(bag.begin(), bag.begin() + middle);
    vector<ull> right(bag.begin() + middle, bag.end());

    vector<ull> left_sums;
    vector<ull> right_sums;

    MakeSubSums(left, left_sums, 0, 0);
    MakeSubSums(right, right_sums, 0, 0);

    sort(right_sums.begin(), right_sums.end());

    ull count = 0;

    for (auto sum : left_sums)
    {
        if (sum > C)
            continue;
        auto iter = upper_bound(right_sums.begin(), right_sums.end(), C - sum);
        count += (iter - right_sums.begin());
    }

    cout << count;

    return 0;
}