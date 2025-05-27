#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    
    stack<char> s;
    
    s.push(number[0]);
    
    int erase_count = 0;
    
    for (size_t i = 1; i < number.length(); i++)
    {
        while (erase_count < k && !s.empty() && s.top() < number[i])
        {
            s.pop();
            erase_count++;
        }
        
        s.push(number[i]);
    }
    
    while (erase_count < k)
    {
        s.pop();
        erase_count++;
    }
    
    while (!s.empty())
    {
        answer = s.top() + answer;
        s.pop();
    }
    
    return answer;
}