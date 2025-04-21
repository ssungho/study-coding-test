#include <iostream>

using namespace std;

int main(void)
{
    long long S;
    cin >> S;

    long long sum = 0;
    long long num = 0;

    while (true)
    {
        num++;
        sum += num;
        if (sum > S)
        {
            num--;
            break;
        }
    }

    cout << num;

    return 0;
}