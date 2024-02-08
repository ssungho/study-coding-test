#include <iostream>

int main(void)
{
    long long A, B, C;
    std::cin >> A >> B >> C;

    long long answer = 1;
    while (B > 0)
    {
        if (B % 2 != 0)
        {
            answer *= A;
            answer %= C;
        }
        A *= A;
        A %= C;
        B /= 2;
    }

    std::cout << answer;

    return 0;
}