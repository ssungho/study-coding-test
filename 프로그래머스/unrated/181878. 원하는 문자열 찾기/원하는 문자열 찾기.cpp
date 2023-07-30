#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) 
{
    for (int i = 0; i < myString.size(); i++)
        myString[i] = toupper(myString[i]);
    
    for (int i = 0; i < pat.size(); i++)
        pat[i] = toupper(pat[i]);
    
    if (myString.find(pat) != string::npos)
        return 1;
        
    return 0;
}