#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    cin >> str;

    int size = (int)str.size();
    bool is_palindrome = true;

    for (int i = 0; i < size / 2; i++)
    {
        if (str[i] != str[size - i - 1])
        {
            is_palindrome = false;
            break;
        }
    }

    cout << is_palindrome << '\n';

    return 0;
}