#include <iostream>
#include <vector>

using namespace std;

constexpr int END_POS{32};
int dice[10]{};
int piece[4]{};
int max_score = 0;
vector<int> board;

void DFS(int index, int score)
{
    if (index == 10)
    {
        max_score = max(max_score, score);
        return;
    }

    int move = dice[index];
    for (int i = 0; i < 4; i++)
    {
        int start = piece[i];
        int pos = start;
        for (int j = 0; j < move; j++)
        {
            if (j == 0 && pos == 5)
                pos = 21;
            else if (j == 0 && pos == 10)
                pos = 25;
            else if (j == 0 && pos == 15)
                pos = 27;
            else if (pos == 26 || pos == 29)
                pos = 24;
            else if (pos == 24)
                pos = 30;
            else if (pos == 31)
                pos = 20;
            else if (pos == 20)
                pos = END_POS;
            else if (pos == END_POS)
                pos = END_POS;
            else
                pos++;
        }

        bool go = true;

        for (int j = 0; j < 4; j++)
        {
            if (j == i) continue;

            if (piece[j] == pos && pos != END_POS)
            {
                go = false;
                break;
            }
        }

        if (go)
        {
            piece[i] = pos;
            DFS(index + 1, score + board[pos]);
            piece[i] = start;
        }
    }
}

int main(void)
{
    board = 
    {
        0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
        22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
        13, 16, 19, 25,
        22, 24,
        28, 27, 26,
        30, 35, 0
    };

    for (int i = 0; i < 10; i++)
    {
        cin >> dice[i];
    }

    DFS(0, 0);

    cout << max_score << '\n';

    return 0;
}