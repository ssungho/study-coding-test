#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string number;
    cin >> number;

    int sum = 0;
    int pos = number.length() - 1;
    bool can = false;

    while (pos >= 0)
    {
        sum += number[pos] - '0';
        if (!can && number[pos] == '0')
        {
            can = true;
        }
        pos--;
    }

    if (sum % 3 != 0 || !can)
        cout << -1;
    else
    {
        sort(number.begin(), number.end(), greater<char>());
        cout << number;
    }

    return 0;
}