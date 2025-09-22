#include <bits/stdc++.h>

using namespace std;

int n, r, c, cnt;

void Recursion(int row, int col, int length)
{
    if (length == 1 && row == r && col == c)
    {
        cout << cnt << '\n';
        return;
    }

    if (row <= r && r < row + length && col <= c && c < col + length)
    {
        int half = length / 2;
        Recursion(row, col, half);
        Recursion(row, col + half, half);
        Recursion(row + half, col, half);
        Recursion(row + half, col + half, half);
    }
    else 
    {
        cnt += length * length;
    }
}

int main(void)
{
    cin >> n >> r >> c;
    int size = pow(2, n);
    Recursion(0, 0, size);

    return 0;
}