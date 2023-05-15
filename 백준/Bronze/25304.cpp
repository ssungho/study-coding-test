#include <iostream>
using namespace std;

int main(void)
{
    long X;
    int N;
    cin >> X >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        X -= a * b;
    }
    if (X == 0)
        cout << "Yes";
    else
        cout << "No";
}