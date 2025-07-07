#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    getline(cin, str);

    for (char& ch : str)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            ch = ch + 13 > 'Z' ? ch - 13 : ch + 13;
        }
        else if ('a' <= ch && ch <= 'z')
        {
            ch = ch + 13 > 'z' ? ch - 13 : ch + 13;
        }
    }

    cout << str << '\n';

    return 0;
}