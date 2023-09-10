#include <iostream>
using namespace std;

char land[202][202];
int result[202][202];
int dx[5]{0, 1, 0, -1, 0};
int dy[5]{-1, 0, 1, 0, 0};
int main()
{
    // 한 변의 길이 N과 떨어뜨릴 횟수 K
    int N, K;
    cin >> N >> K;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            char temp;
            cin >> temp;
            land[i][j] = temp;
        }
    }

    int max_value = 0;
    for (int i = 0; i < K; i++)
    {
        int y, x;
        cin >> y >> x;
        int ny, nx;
        for (int j = 0; j < 5; j++)
        {
            ny = y + dy[j];
            nx = x + dx[j];

            if (land[ny][nx] == '0')
            {
                result[ny][nx] += 1;
            }
            else if (land[ny][nx] == '@')
            {
                result[ny][nx] += 2;
            }

            if (result[ny][nx] > max_value)
            {
                max_value = result[ny][nx];
            }
        }
    }

    cout << max_value;
    return 0;
}