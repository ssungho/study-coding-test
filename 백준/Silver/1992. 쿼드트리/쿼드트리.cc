#include <iostream>
#include <string>

using namespace std;

int N;
char map[64][64]{};

string dfs(int y, int x, int n)
{
    string temp = "";

    if (n == 1)
    {
        return temp + map[y][x];
    }

    int half = n / 2;
    string pos1 = dfs(y, x, half);
    string pos2 = dfs(y, x + half, half);
    string pos3 = dfs(y + half, x, half);
    string pos4 = dfs(y + half, x + half, half);

    if (pos1.size() == 1 && pos1 == pos2 && pos2 == pos3 && pos3 == pos4)
    {
        temp += pos1;
    }
    else
    {
        temp += '(' + (pos1 + pos2 + pos3 + pos4) + ')';
    }

    return temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < N; j++)
        {
            map[i][j] = row[j];
        }
    }

    cout << dfs(0, 0, N) << '\n';

    return 0;
}