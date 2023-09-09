#include <iostream>

using namespace std;
int arr[10][10];

int main(void)
{
    int max = -1;
    int x;
    int y;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            int temp;
            cin >> temp;
            arr[j][i] = temp;
            if (temp >= max)
            {
                max = temp;
                x = j;
                y = i;
            }
        }
    }
    cout << max << '\n' << y << " " << x;

    return 0;
}