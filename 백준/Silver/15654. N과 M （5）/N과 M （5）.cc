#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(vector<int>& nums, vector<int> &vec, vector<bool>& visited)
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

    for (int i = 0; i < N; i++) 
    {
        if (visited[i]) 
            continue;

        int num = nums[i];

        vec.push_back(num);
        visited[i] = true;

        Backtracking(nums, vec, visited);

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
    vector<bool> visited(N);
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    Backtracking(nums, v, visited);

    return 0;
}