#include <iostream>
using namespace std;
int board[1002][1002];
int count = 0;
int Find(int n, int k)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (board[i][j] == 0)
            {
                int cnt = 0;

                // 둘러싸고있는 지역 확인
                if (board[i - 1][j - 1] == 1)
                    cnt++;
                if (board[i][j - 1] == 1)
                    cnt++;
                if (board[i + 1][j - 1] == 1)
                    cnt++;
                if (board[i - 1][j] == 1)
                    cnt++;
                if (board[i + 1][j] == 1)
                    cnt++;
                if (board[i - 1][j + 1] == 1)
                    cnt++;
                if (board[i][j + 1] == 1)
                    cnt++;
                if (board[i + 1][j + 1] == 1)
                    cnt++;

                if (cnt == k)
                    count++;
            }
        }
    }
    return count;
}

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }
    cout << Find(N, K);

    return 0;
}