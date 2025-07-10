#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    while (T--)
    {
        stack<char> s;
        string str;
        cin >> str;
        
        bool pass = true;
        for (int i = 0; i < (int)str.size(); i++)
        {
            if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else
            {
                if (s.empty())
                {
                    pass = false;
                    break;
                }
                if (s.top() == '(')
                {
                    s.pop();
                }
            }
        }

        if (s.empty() && pass)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}