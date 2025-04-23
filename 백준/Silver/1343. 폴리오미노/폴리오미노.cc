#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string board = "";
    cin >> board;

    int length = (int)board.length();

    int start_index = 0;
    int count_x = 0;

    for (int i = 0; i < length; i++)
    {
        if (board[i] == '.')
        {
            start_index = i + 1;
            count_x = 0;
            continue;
        }

        count_x++;
        if (count_x == 2)
        {
            board.replace(start_index, 2, "BB");
            start_index = i + 1;
            count_x = 0;
        }
    }

    if (string::npos != board.find('X'))
    {
        cout << -1;
        return 0;
    }

    start_index = 0;

    for (int i = 0; i < length; i++)
    {
        if (board[i] == '.')
        {
            start_index = i + 1;
            count_x = 0;
            continue;
        }

        count_x++;
        if (count_x == 4)
        {
            board.replace(start_index, 4, "AAAA");
            start_index = i + 1;
            count_x = 0;
        }
    }

    cout << board;

    return 0;
}