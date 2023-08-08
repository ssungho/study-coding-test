#include <iostream>
#include <string>

using namespace std;

int main (void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string s;
        cin >> s;

        int cnt = 0; 
        int answer = 0;

        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == 'O')
                cnt++;
            else
                cnt = 0;

            answer += cnt;
        }
        cout << answer << '\n';
    }

    return 0;
}