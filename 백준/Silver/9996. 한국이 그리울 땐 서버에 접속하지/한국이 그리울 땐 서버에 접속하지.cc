#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    auto pos = pattern.find('*');
    int cntBack = pattern.size() - pos - 1;
    
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        bool can = true;

        if (pattern.size() - 1 > str.size())
        {
            can = false;
        }
        else
        {
            for (int j = 0; j < pos; j++)
            {
                if (str[j] != pattern[j])
                {
                    can = false;
                    break;
                }
            }

            for (int j = 0; j < cntBack; j++)
            {
                if (str[str.size() - 1 - j] != pattern[pattern.size() - 1 - j])
                {
                    can = false;
                    break;
                }
            }
        }

        if (can)
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}