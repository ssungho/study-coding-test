#include <iostream>
using namespace std;

int paper[101][101];
int main(void)
{
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = x; j < x + 10; j++)
        {
            for (int k = y; k < y + 10; k++)
                paper[k][j] = 1;
        }
    }

    int area = 0;
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
            area += paper[j][i];
    }
    cout << area;

    return 0;
}