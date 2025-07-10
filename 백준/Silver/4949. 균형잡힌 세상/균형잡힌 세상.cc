#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        stack<char> s;
        string str;
        
        getline(cin, str);
        if (str == ".")
            break;
        
        int length = (int)str.length();
        bool pass = true;

        for (int i = 0; i < length - 1; i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    pass = false;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
            else if (str[i] == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    pass = false;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
        }

        if (s.empty() && pass)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}