#include <iostream>
#include <vector>

using namespace std;

void Backtracking(vector<int> &v, vector<int> &temp, vector<bool> &visited, int &max_sum)
{
    if (temp.size() == v.size())
    {
        int result = 0;
        for (int i = 1; i < (int)v.size(); i++)
        {
            result += abs(v[temp[i - 1]] - v[temp[i]]);
        }
        max_sum = max(result, max_sum);
    }

    for (int i = 0; i < (int)v.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            temp.push_back(i);
            Backtracking(v, temp, visited, max_sum);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    int N;
    cin >> N;

    vector<int> v(N);
    vector<bool> visited(N);
    vector<int> temp;
    int max_sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    Backtracking(v, temp, visited, max_sum);
    cout << max_sum;

    return 0;
}