#include <iostream>
#include <vector>

using namespace std;

int N, M;

void Backtracking(vector<int> &vec, vector<bool> &visited)
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

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] || (vec.size() > 0 && vec.back() > i))
            continue;

        vec.push_back(i);
        visited[i] = true;

        Backtracking(vec, visited);

        vec.pop_back();
        visited[i] = false;
    }
}

int main(void)
{
    cin >> N >> M;

    vector<int> v;
    vector<bool> visited(N + 1, false);

    Backtracking(v, visited);

    return 0;
}