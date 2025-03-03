#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(vector<int> &vec, vector<int> &nums, int start)
{
    if (vec.size() == (size_t)M)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }

        cout << '\n';

        return;
    }

    int prev = 0;
    for (int i = start; i < N; i++)
    {
        int num = nums[i];

        if (prev == nums[i])
        {
            continue;
        }

        prev = num;

        vec.push_back(num);

        Backtracking(vec, nums, i);

        vec.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M;

    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<int> v;
    v.reserve(nums.size());

    Backtracking(v, nums, 0);

    return 0;
}