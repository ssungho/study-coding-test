#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(vector<int> &vec, vector<int> &nums)
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
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];

        if (prev == nums[i])
            continue;

        prev = num;

        vec.push_back(num);

        Backtracking(vec, nums);

        vec.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M;
    set<int> s;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    vector<int> nums(s.size());

    int cnt = 0;
    for (auto num : s)
    {
        nums[cnt++] = num;
    }

    vector<int> v;
    v.reserve(nums.size());

    Backtracking(v, nums);

    return 0;
}