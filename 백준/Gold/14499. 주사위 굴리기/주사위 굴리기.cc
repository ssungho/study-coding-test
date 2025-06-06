#include <iostream>
#include <vector>

using namespace std;

constexpr int DIR_SIZE{4};
constexpr int dy[DIR_SIZE]{0, 0, -1, 1};
constexpr int dx[DIR_SIZE]{1, -1, 0, 0};

void TurnDice(int *dice, int up_index, int next1, int next2, int next3)
{
    int temp = dice[up_index];
    dice[up_index] = dice[next1];
    dice[next1] = dice[next2];
    dice[next2] = dice[next3];
    dice[next3] = temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int dice_y, dice_x;
    cin >> dice_y >> dice_x;

    int K;
    cin >> K;

    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    int dice[]{0, 0, 0, 0, 0, 0};

    vector<int> commands(K, 0);
    for (int i = 0; i < K; i++)
    {
        cin >> commands[i];
        --commands[i];
    }

    for (auto dir : commands)
    {
        int dice_ny = dice_y + dy[dir];
        int dice_nx = dice_x + dx[dir];

        if (0 > dice_ny || dice_ny >= N ||
            0 > dice_nx || dice_nx >= M)
        {
            continue;
        }

        dice_y = dice_ny;
        dice_x = dice_nx;

        if (dir == 0)
        {
            TurnDice(dice, 0, 1, 2, 3);
        }
        else if (dir == 1)
        {
            TurnDice(dice, 0, 3, 2, 1);
        }
        else if (dir == 2)
        {
            TurnDice(dice, 0, 4, 2, 5);
        }
        else
        {
            TurnDice(dice, 0, 5, 2, 4);
        }

        if (map[dice_y][dice_x] == 0)
        {
            map[dice_y][dice_x] = dice[2];
        }
        else
        {
            dice[2] = map[dice_y][dice_x];
            map[dice_y][dice_x] = 0;
        }

        cout << dice[0] << '\n';
    }

    return 0;
}