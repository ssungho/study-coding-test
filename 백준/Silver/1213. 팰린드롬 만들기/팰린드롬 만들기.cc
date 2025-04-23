#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{

    string en_name;
    cin >> en_name;

    map<char, int> m;

    int length = (int)en_name.length();

    for (int i = 0; i < length; i++)
    {
        auto iter = m.find(en_name[i]);
        if (iter != m.end())
        {
            iter->second++;
        }
        else
        {
            m.insert({en_name[i], 1});
        }
    }

    string front = "";
    string back = "";
    string mid = "";

    int count = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second % 2 == 1)
        {
            count++;
            mid = iter->first;
        }
        
        if (count > 1)
            break;

        for (int i = 0; i < iter->second / 2; i++)
        {
            front += iter->first;
            back = iter->first + back;
        }
    }

    if (count > 1)
        cout << "I'm Sorry Hansoo";
    else
        cout << front + mid + back;

    return 0;
}