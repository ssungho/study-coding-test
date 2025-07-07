#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string name;
    cin >> name;

    int alphabet[26]{};
    for (char ch : name)
    {
        alphabet[ch - 'A']++;
    }

    int cntOdd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] % 2 == 1)
        {
            cntOdd++;
        }
    }

    string temp = "";
    if (cntOdd == 0)
    {
        for (int i = 0; i < 26; i++)
        {
            int cnt = alphabet[i];
            for (int j = 0; j < cnt / 2; j++)
            {
                temp.push_back(i + 'A');
            }
        }

        temp.append(temp.rbegin(), temp.rend());
        cout << temp << '\n';
    }
    else if (cntOdd == 1)
    {
        char center;
        for (int i = 0; i < 26; i++)
        {
            int cnt = alphabet[i];
            if (cnt % 2 == 1)
                center = i + 'A';

            for (int j = 0; j < cnt / 2; j++)
            {
                temp.push_back(i + 'A');
            }
        }

        string reverse(temp.rbegin(), temp.rend());
        temp.push_back(center);
        temp.append(reverse);
        cout << temp << '\n';
    }
    else
    {
        cout << "I'm Sorry Hansoo\n";
    }

    return 0;
}