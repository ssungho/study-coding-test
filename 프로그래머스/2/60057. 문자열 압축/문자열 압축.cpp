#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = s.size();
    int n = s.size();
    
    for (int i = 1; i <= n / 2; i++) 
    {
        string compressed = "";
        string prev = s.substr(0, i);
        int count = 1;
        
        for (int j = i; j < n; j += i) 
        {
            string curr = s.substr(j, i);
            
            if (prev == curr) 
            {
                count++;
            }
            else 
            {
                if (count > 1) 
                {
                    compressed += to_string(count);
                }
                
                compressed += prev;
                prev = curr;
                count = 1;
            }
        }
        
        if (count > 1) 
        {
            compressed += to_string(count);
        }
        compressed += prev;
        
        answer = min(answer, (int)compressed.size());
    }
    
    return answer;
}