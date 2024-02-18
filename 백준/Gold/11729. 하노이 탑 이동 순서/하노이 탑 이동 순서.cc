#include <iostream>
#include <cmath>
using namespace std;

void moveHanoi(int cnt, int start, int middle, int end)
{
    if (cnt == 1)
    {
        cout << start << " " << end << '\n';
    }
    else
    {
        moveHanoi(cnt - 1, start, end, middle);
        cout << start << " " << end << '\n';
        moveHanoi(cnt - 1, middle, start, end);
    }
}

int main(void)
{
    int n;
    cin >> n;

    cout << (int)pow(2, n) - 1 << '\n';
    moveHanoi(n, 1, 2, 3);

    return 0;
}