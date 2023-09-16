#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
    string str;
    set<string> sub_strings;
    
    cin >> str;
    for (int i = 0; i < str.size(); i++) 
    {
        string sub = "";
        for (int j = i; j < str.size(); j++) 
        {
            sub += str[j];
            sub_strings.insert(sub);
        }
    }

    cout << sub_strings.size();
    
    return 0;
}