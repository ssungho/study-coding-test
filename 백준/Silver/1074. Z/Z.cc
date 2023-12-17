#include <iostream>
#include <cmath>
using namespace std;

int count = 0;
int N, r, c;

void Find(int row, int col, int length)
{
    if (row == r && col == c)
    {
        cout << count << endl;
        return;
    }

    if (r >= row && r < row + length && c >= col && c < col + length)
    {
        int newLength = length / 2;
        Find(row, col, newLength);
        Find(row, col + newLength, newLength);
        Find(row + newLength, col, newLength);
        Find(row + newLength, col + newLength, newLength);
    }
    else
    {
        count += length * length;
    }
}

int main(void)
{
    cin >> N >> r >> c;

    int length = pow(2, N);
    Find(0, 0, length);

    return 0;
}