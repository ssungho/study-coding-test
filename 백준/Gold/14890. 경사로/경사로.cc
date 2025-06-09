#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CanPassPath(vector<int> &path, int N, int L)
{
    vector<bool> used(N, false);

    for (int i = 0; i < N - 1; i++)
    {
        int diff = path[i + 1] - path[i];

        if (diff == 0)
        {
            continue;
        }
        else if (diff == 1)
        {
            for (int j = i; j > i - L; j--)
            {
                if (j < 0 || path[j] != path[i] || used[j])
                    return false;

                used[j] = true;
            }
        }
        else if (diff == -1)
        {
            for (int j = i + 1; j <= i + L; j++)
            {
                if (j >= N || path[j] != path[i + 1] || used[j])
                    return false;

                used[j] = true;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int N, L;
    cin >> N >> L;

    vector<vector<int>> map(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        vector<int> row(map[i]);
        if (CanPassPath(row, N, L))
        {
            result++;
        }

        vector<int> col(N, 0);
        for (int j = 0; j < N; j++)
        {
            col[j] = map[j][i];
        }

        if (CanPassPath(col, N, L))
        {
            result++;
        }
    }

    cout << result;

    return 0;
}