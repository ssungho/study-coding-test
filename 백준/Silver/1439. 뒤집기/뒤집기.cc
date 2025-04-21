#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    cin >> S;

    int length = (int)S.length();

    int cnt = 1;
    char ch = S[0];

    for (int i = 0; i < length; i++)
    {
        if (ch != S[i])
        {
            cnt++;
            ch = S[i];
        }
    }

    cout << cnt / 2;

    return 0;
}