#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) 
{
    char nums[]{'0','1','2','3','4','5','6','7','8','9'};
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