#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) 
{
    string answer = "";
    for(int i = 0; i < s.length(); i++)
    {
        char temp = s[i];
        
        if(i == 0 || s[i - 1] == ' ')
            temp = toupper(s[i]);
        else
            temp = tolower(s[i]);
        
        answer += temp;
    }
    
    return answer;
}