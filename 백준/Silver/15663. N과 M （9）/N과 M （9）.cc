#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(vector<int> &vec, vector<int> &nums, vector<bool> &visited)
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
    for (int i = 0; i < N; i++)
    {
        int num = nums[i];

        if (visited[i] || prev == num)
        {
            continue;
        }

        prev = num;
        vec.push_back(num);
        visited[i] = true;

        Backtracking(vec, nums, visited);

        vec.pop_back();
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M;

    vector<int> v;
    vector<int> nums(N);
    vector<bool> visited(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    Backtracking(v, nums, visited);

    return 0;
}