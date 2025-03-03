#include <iostream>
#include <vector>

using namespace std;

int N, count;

void Backtracking(int row, vector<bool> &cols, vector<bool> &right_ups, vector<bool> &right_downs)
{
    if (row == N)
    {
        count++;
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (cols[col] || right_ups[row + col] || right_downs[row - col + (N - 1)])
        {
            continue;
        }

        cols[col] = true;
        right_ups[row + col] = true;
        right_downs[row - col + (N - 1)] = true;

        Backtracking(row + 1, cols, right_ups, right_downs);

        cols[col] = false;
        right_ups[row + col] = false;
        right_downs[row - col + (N - 1)] = false;
    }
}

int main(void)
{
    cin >> N;

    vector<bool> cols(N);
    vector<bool> right_ups(2 * N - 1);
    vector<bool> right_downs(2 * N - 1);

    Backtracking(0, cols, right_ups, right_downs);

    cout << count;

    return 0;
}
