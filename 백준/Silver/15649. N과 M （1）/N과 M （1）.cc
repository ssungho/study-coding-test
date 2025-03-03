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
        if (!visited[i])
        {
            visited[i] = true;
            vec.push_back(i);
            Backtracking(vec, visited);
            vec.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> N >> M;

    vector<int> v;
    vector<bool> visitied(N + 1, false);

    Backtracking(v, visitied);

    return 0;
}