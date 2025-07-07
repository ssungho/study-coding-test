#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string str;
    cin >> str;

    string strReverse(str);
    reverse(strReverse.begin(), strReverse.end());

    cout << (str == strReverse) << '\n';

    return 0;
}