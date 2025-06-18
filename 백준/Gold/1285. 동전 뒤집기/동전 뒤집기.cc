#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
int min_count{INT_MAX};
constexpr int max_n{20};
char coins[max_n][max_n]{};

int CountT()
{
    int count = 0;
    for (auto& row : coins)
    {
        for (char coin : row)
        {
            if (coin == 'T')
                count++;
        }
    }
    return count;
}

void ReversRow(int index)
{
    for (int i = 0; i < N; i++)
    {
        coins[index][i] = (coins[index][i] == 'T') ? 'H' : 'T';
    }
}

void Search(int index)
{
    if (index == N)
    {
        int count = CountT();
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

    Search(index + 1);
    ReversRow(index);
    Search(index + 1);
    ReversRow(index);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> coins[i][j];
        }
    }

    min_count = CountT();

    Search(0);

    cout << min_count << '\n';

    return 0;
}