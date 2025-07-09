#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> s{'a', 'e', 'i', 'o', 'u'};

bool test(const string &password)
{
    int size = (int)password.size();
    bool condition1 = false;
    bool condition2 = true;
    bool condition3 = true;

    for (int i = 0; i < size; i++)
    {
        if (s.find(password[i]) != s.end())
            condition1 = true;

        if (i + 1 < size && password[i] == password[i + 1])
        {
            if (!(password[i] == 'e' || password[i] == 'o'))
            {
                condition2 = false;
            }
        }

        int count = 0;
        bool check = true;

        for (int j = 0; j <= 2; j++)
        {
            if (i + j >= size)
            {
                check = false;
                break;
            }

            if (s.find(password[i + j]) != s.end())
            {
                count++;
            }
        }

        if ((count == 0 || count == 3) && check)
        {
            condition3 = false;
        }
    }

    return condition1 && condition2 && condition3;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        string password;
        cin >> password;

        if (password == "end")
            break;

        if (test(password))
            cout << '<' << password << "> is acceptable.\n";
        else
            cout << '<' << password << "> is not acceptable.\n";
    }

    return 0;
}