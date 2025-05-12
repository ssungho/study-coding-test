#include <iostream>
#include <bitset>

using namespace std;

constexpr int BIT_SIZE{7};

int main(void)
{
    int X;
    cin >> X;

    bitset<BIT_SIZE> bX = X;

    int count = 0;
    for (int i = 0; i < BIT_SIZE; i++)
    {
        if (bX[i]) count++;
    }

    cout << count;

    return 0;
}