#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;
        string answer = "";

        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++)
        {
            char c = s[j];
            for(int k = 0; k < cnt; k++)
            {
                answer += c;
            }
        }
        cout << answer << '\n';
    }
    
    return 0;
}