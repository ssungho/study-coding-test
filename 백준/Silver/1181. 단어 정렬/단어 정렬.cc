#include <iostream>
#include <algorithm>

using namespace std;

int compare(string a, string b)
{
    if (a.length() == b.length()) 
        return a < b; 
    
    else
        return a.length() < b.length(); 
}

int main(void) 
{
    int n = 0;
    cin >> n;

    string s[20000];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort(s, s + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && s[i] == s[i - 1])
            continue;

        cout << s[i] << '\n';
    }

    return 0;
}