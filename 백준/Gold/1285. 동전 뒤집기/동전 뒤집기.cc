#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
int min_count{INT_MAX};

int CountT(vector<vector<char>> &coins)
{
    int count = 0;
    for (auto &row : coins)
    {
        for (char coin : row)
        {
            if (coin == 'T')
                count++;
        }
    }
    return count;
}

void ReversRow(vector<char> &row)
{
    for (int i = 0; i < N; i++)
    {
        row[i] = (row[i] == 'T') ? 'H' : 'T';
    }
}

void Search(vector<vector<char>> &coins, int index)
{
    if (index == N)
    {
        int count = CountT(coins);
        for (int i = 0; i < N; i++)
        {
            int t_count = 0;
            for (int j = 0; j < N; j++)
            {
                if (coins[j][i] == 'T')
                    t_count++;
            }

            int h_count = N - t_count;
            if (t_count > h_count)
            {
                count -= t_count;
                count += h_count;
            }
        }

        min_count = min(min_count, count);
        return;
    }

    Search(coins, index + 1);
    ReversRow(coins[index]);
    Search(coins, index + 1);
    ReversRow(coins[index]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<vector<char>> coins(N, vector<char>(N, ' '));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> coins[i][j];
        }
    }

    min_count = CountT(coins);

    Search(coins, 0);

    cout << min_count << '\n';

    return 0;
}