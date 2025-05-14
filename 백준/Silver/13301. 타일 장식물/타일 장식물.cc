#include <iostream>

using namespace std;

long long length[81]{};

int main(void)
{
    int N;
    cin >> N;

    length[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        length[i] = length[i - 1] + length[i - 2];
    }

    if (N == 1)
        cout << 4;
    else if (N == 2)
        cout << 6;
    else
        cout << length[N] * 4 + length[N - 1] * 2;

    return 0;
}