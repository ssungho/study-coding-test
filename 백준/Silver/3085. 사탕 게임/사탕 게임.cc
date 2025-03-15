#include <iostream>
#include <memory>

using namespace std;

// 우 하
int dy[2]{0, 1};
int dx[2]{1, 0};

char board[50][50]{};
int N{};

int GetMaxCandySeq()
{
    int acc = 0;
    int max_seq = 0;

    for (int i = 0; i < N; i++)
    {
        acc = 1;

        for (int j = 1; j < N; j++)
        {
            if (board[j][i] == board[j - 1][i])
            {
                acc++;
            }
            else
            {
                max_seq = max(max_seq, acc);
                acc = 1;
            }
        }
        
        max_seq = max(max_seq, acc);
    }

    for (int i = 0; i < N; i++)
    {
        acc = 1;

        for (int j = 1; j < N; j++)
        {
            if (board[i][j] == board[i][j - 1])
            {
                acc++;
            }
            else
            {
                max_seq = max(max_seq, acc);
                acc = 1;
            }
        }

        max_seq = max(max_seq, acc);
    }

    return max_seq;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int max_seq = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int ny = dy[k] + i;
                int nx = dx[k] + j;

                if (ny < N && nx < N && board[ny][nx] != board[i][j])
                {
                    swap(board[ny][nx], board[i][j]);

                    max_seq = max(max_seq, GetMaxCandySeq());

                    swap(board[ny][nx], board[i][j]);
                }
            }
        }
    }

    cout << max_seq;

    return 0;
}