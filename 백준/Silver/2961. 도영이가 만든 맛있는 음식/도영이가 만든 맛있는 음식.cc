#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
long long min_diff = LLONG_MAX;

void Backtracking(vector<pair<int, int>> &v, vector<int> &indexes, vector<bool> &visited, int index)
{

    if (indexes.size() >= 1)
    {
        long long mul = 1, sum = 0;
        for (int i : indexes)
        {
            pair<int, int> &p = v[i];
            mul *= p.first;
            sum += p.second;
        }

        min_diff = min(min_diff, abs(mul - sum));
    }

    for (int i = index; i < N; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        indexes.push_back(i);

        Backtracking(v, indexes, visited, i + 1);

        visited[i] = false;
        indexes.pop_back();
    }
}

int main(void)
{
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    vector<bool> visited(N, false);
    vector<int> indexes;

    Backtracking(v, indexes, visited, 0);

    cout << min_diff;

    return 0;
}