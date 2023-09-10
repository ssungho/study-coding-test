#include <iostream>
using namespace std;

int main(void)
{
    long N;
    cin >> N;

    long item[3] = {1, 7, 14};

    int cnt = 0;
    while (N > 0)
    {
        if (N > 14)
        {
            cnt += N / 14;
            N %= 14;
        }
        if (N > 7)
        {
            cnt += N / 7;
            N %= 7;
        }
        else
        {
            cnt += N;
            N = 0;
        }
    }
    cout << cnt;
    return 0;
}