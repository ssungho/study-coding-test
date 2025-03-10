#include <iostream>

using namespace std;

int main(void)
{
    int n, jm, hs, round = 0;
    cin >> n >> jm >> hs;

    while (jm != hs)
    {
        jm = (jm + 1) / 2;
        hs = (hs + 1) / 2;
        round++;
    }

    cout << round;

    return 0;
}