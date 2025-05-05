#include <iostream>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dx = x1 - x2;
        int dy = y1 - y2;
        int dist = dx * dx + dy * dy;
        int r_sub = (r1 - r2) * (r1 - r2);
        int r_sum = (r1 + r2) * (r1 + r2);

        int result = -1;

        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            result = -1;
        }
        else if (dist == r_sub || dist == r_sum)
        {
            result = 1;
        }
        else if (r_sub < dist && dist < r_sum)
        {
            result = 2;
        }
        else
        {
            result = 0;
        }

        cout << result << '\n';
    }

    return 0;
}