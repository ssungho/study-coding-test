#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    long N;
    vector<int> shirts(6, 0);
    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> shirts[i];
    }

    long T, P;
    cin >> T >> P;

    long shirt = 0;
    for (int i = 0; i < 6; i++)
    {
        shirt += shirts[i] / T;
        if (shirts[i] % T != 0)
            shirt++;
    }

    long pen = N / P;
    long pen_mod = N % P;

    cout << shirt << '\n'
         << pen << " " << pen_mod;

    return 0;
}