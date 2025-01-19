#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<string> suffixes;
    int length = str.length();

    for (int i = 0; i < length; i++)
    {
        suffixes.push_back(str.substr(i));
    }

    sort(suffixes.begin(), suffixes.end());

    for (const string &suffix : suffixes)
    {
        cout << suffix << endl;
    }

    return 0;
}
