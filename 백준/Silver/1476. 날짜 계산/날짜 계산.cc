#include <iostream>

using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;

    int earth = 1, sun = 1, moon = 1;
    int cnt = 1;

    while (true)
    {
        if (earth == E && sun == S && moon == M)
            break;

        cnt++;
        earth = (earth % 15) + 1;
        sun = (sun % 28) + 1;
        moon = (moon % 19) + 1;
    }

    cout << cnt << endl;

    return 0;
}
