#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int digit = 1;
    int copy = N;

    while (int(copy /= 10) != 0)
    {
        digit++;
    }

    long result = 0;

    for (int i = 1; i <= N; i *= 10)
    {
        result += N - i + 1;
    }

    cout << result;

    return 0;
}