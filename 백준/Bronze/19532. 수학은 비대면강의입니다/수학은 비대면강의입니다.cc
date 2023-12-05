#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    int x, y;
    for (int i = -999; i <= 999; i++)
    {
        x = i;
        for (int j = -999; j <= 999; j++)
        {
            y = j;

            int q1 = a * x + b * y - c;
            int q2 = d * x + e * y - f;
            if(q1 == 0 && q2 == 0)
            {
                cout << x << " " << y;
                return 0;
            }
        }
    }

    return 0;
}