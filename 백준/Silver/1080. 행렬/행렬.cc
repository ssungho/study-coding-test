#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Reverse(vector<vector<bool>> &matrix, int row, int col)
{
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            matrix[i][j] = !matrix[i][j];
        }
    }
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> from_matrix(N, vector<bool>(M, false));
    vector<vector<bool>> to_matrix(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            if (row[j] == '1')
            {
                from_matrix[i][j] = true;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            if (row[j] == '1')
            {
                to_matrix[i][j] = true;
            }
        }
    }

    int result = 0;

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if (from_matrix[i][j] != to_matrix[i][j])
            {
                Reverse(from_matrix, i, j);
                result++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (from_matrix[i][j] != to_matrix[i][j])
            {
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << result;

    return 0;
}