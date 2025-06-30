#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

constexpr int command_length{3};
int result = INT_MAX;
int N, M, K;

int GetMinRowSum(const vector<vector<int>> &array)
{
    int min_sum = INT_MAX;
    for (const auto &row : array)
    {
        int sum = 0;
        for (auto val : row)
        {
            sum += val;
        }
        min_sum = min(min_sum, sum);
    }
    return min_sum;
}

void RotateR(vector<vector<int>> &array, int r, int c, int s)
{
    pair<int, int> left_top = {r - s - 1, c - s - 1};
    pair<int, int> right_bottom = {r + s - 1, c + s - 1};

    while (left_top.first != right_bottom.first)
    {
        int temp = array[left_top.first][left_top.second];

        for (int i = left_top.first; i < right_bottom.first; i++)
            array[i][left_top.second] = array[i + 1][left_top.second];

        for (int i = left_top.second; i < right_bottom.second; i++)
            array[right_bottom.first][i] = array[right_bottom.first][i + 1];

        for (int i = right_bottom.first; i > left_top.first; i--)
            array[i][right_bottom.second] = array[i - 1][right_bottom.second];

        for (int i = right_bottom.second; i > left_top.second; i--)
            array[left_top.first][i] = array[left_top.first][i - 1];

        array[left_top.first][left_top.second + 1] = temp;

        left_top = {left_top.first + 1, left_top.second + 1};
        right_bottom = {right_bottom.first - 1, right_bottom.second - 1};
    }
}

void DFS(vector<vector<int>>& array, vector<vector<int>> &commands, vector<bool>& visited, int index, int count)
{
    if (count == K)
    {
        result = min(result, GetMinRowSum(array));
        return;
    }

    for (int i = 0; i < K; i++)
    {
        if (!visited[i]) 
        {
            visited[i] = true;
            auto copy = array;
            RotateR(array, commands[i][0], commands[i][1], commands[i][2]);
            DFS(array, commands, visited, i + 1, count + 1);
            array = copy;
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    }

    vector<vector<int>> commands(K, vector<int>(command_length, 0));
    for (int i = 0; i < K; i++)
    {
        cin >> commands[i][0] >> commands[i][1] >> commands[i][2];
    }

    vector<bool> visited(K, false);
    DFS(A, commands, visited, 0, 0);

    cout << result << '\n';

    return 0;
}