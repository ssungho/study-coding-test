#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(vector<int> &vec, vector<int> &nums, vector<bool> &visited, int start)
{
    if (vec.size() == M)
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

        if (visited[i] || prev == nums[i])
            continue;

        prev = num;

        vec.push_back(num);
        visited[i] = true;

        Backtracking(vec, nums, visited, i);

        vec.pop_back();
        visited[i] = false;
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

    vector<bool> visited(N);
    vector<int> v;
    v.reserve(8);

    Backtracking(v, nums, visited, 0);

    return 0;
}