#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int alphabetArray[26]{};
    string str;
    cin >> str;
    
    for (char ch : str)
    {
        alphabetArray[ch - 'a']++;
    }

    for (int alphabetCnt : alphabetArray)
    {
        cout << alphabetCnt << " ";
    }

    return 0;
}