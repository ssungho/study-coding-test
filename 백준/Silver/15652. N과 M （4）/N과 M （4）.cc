#include <iostream>
#include <vector>

using namespace std;

int N, M;

void Backtracking(vector<int> &vec, int start)
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

    for (int i = 1; i <= N; i++) 
    {
        if (vec.size() > 0 && vec.back() > i)
            continue;

        vec.push_back(i);
        Backtracking(vec, i);
        vec.pop_back();
    }
   
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M;

    vector<int> v;
    vector<bool> visited;

    Backtracking(v, 1);

    return 0;
}