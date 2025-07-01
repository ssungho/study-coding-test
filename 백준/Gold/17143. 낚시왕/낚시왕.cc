#include <iostream>
#include <vector>

using namespace std;

struct Shark
{
    int r;
    int c;
    int s;
    int d;
    int z;
};

int main(void)
{
    int R, C, M;
    cin >> R >> C >> M;

    vector<vector<int>> pool(R, vector<int>(C, -1));
    vector<Shark> sharks(M);
    vector<bool> invalid(M, false);

    for (int i = 0; i < M; i++)
    {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        --sharks[i].r;
        --sharks[i].c;
        pool[sharks[i].r][sharks[i].c] = i;
    }

    int sum = 0;

    for (int i = 0; i < C; i++)
    {
        int near_index = -1;
        for (int j = 0; j < R; j++)
        {
            if (pool[j][i] != -1)
            {
                near_index = pool[j][i];
                invalid[near_index] = true;
                pool[j][i] = -1;
                break;
            }
        }

        if (near_index != -1)
        {
            sum += sharks[near_index].z;
        }

        vector<vector<int>> new_pool(R, vector<int>(C, -1));

        for (int j = 0; j < M; j++)
        {
            if (invalid[j])
                continue;

            auto &shark = sharks[j];

            int move = shark.s;
            if (shark.d == 1 || shark.d == 2)
                move %= 2 * (R - 1);
            else
                move %= 2 * (C - 1);

            while (move--)
            {
                if (shark.d == 1)
                {
                    if (shark.r - 1 < 0)
                    {
                        shark.d = 2;
                        shark.r++;
                    }
                    else
                        shark.r--;
                }
                else if (shark.d == 2)
                {
                    if (shark.r + 1 == R)
                    {
                        shark.d = 1;
                        shark.r--;
                    }
                    else
                        shark.r++;
                }
                else if (shark.d == 3)
                {
                    if (shark.c + 1 == C)
                    {
                        shark.d = 4;
                        shark.c--;
                    }
                    else
                        shark.c++;
                }
                else
                {
                    if (shark.c - 1 < 0)
                    {
                        shark.d = 3;
                        shark.c++;
                    }
                    else
                        shark.c--;
                }
            }

            if (new_pool[shark.r][shark.c] == -1)
            {
                new_pool[shark.r][shark.c] = j;
            }
            else if (shark.z > sharks[new_pool[shark.r][shark.c]].z)
            {
                invalid[new_pool[shark.r][shark.c]] = true;
                new_pool[shark.r][shark.c] = j;
            }
            else
            {
                invalid[j] = true;
            }
        }

        pool = new_pool;
    }

    cout << sum << '\n';

    return 0;
}