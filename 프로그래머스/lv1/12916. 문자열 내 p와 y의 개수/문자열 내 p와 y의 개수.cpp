#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int cnt_p = 0;
    int cnt_y = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'p' || s[i] == 'P')
            cnt_p++;
        if (s[i] == 'y' || s[i] == 'Y')
            cnt_y++;
    }

    if (cnt_p == cnt_y)
        return true;
    else
        return false;
}