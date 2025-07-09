#include <iostream>

using namespace std;

char sky[101][101]{};
int result[101][101]{};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> sky[i][j];
            result[i][j] = -1;
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (sky[i][j] == 'c')
            {
                result[i][j] = 0;
                int count = 1;
                while (j + 1 < W && sky[i][j + 1] != 'c')
                {
                    result[i][j + 1] = count;
                    count++;
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}