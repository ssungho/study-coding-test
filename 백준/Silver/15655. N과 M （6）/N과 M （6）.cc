#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(vector<int>& nums, vector<int> &vec, int start)
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

    for (int i = start; i < N; i++) 
    {
        int num = nums[i];

        vec.push_back(num);

        Backtracking(nums, vec, i + 1);

        vec.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M;

    vector<int> v;
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    Backtracking(nums, v, 0);

    return 0;
}