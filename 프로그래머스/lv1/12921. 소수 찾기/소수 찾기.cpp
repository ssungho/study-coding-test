#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<bool> v(n + 1, true);
    
    for(int i = 2; i < sqrt(n) + 1; i++)
    {
        if(v[i] == true)
        {
            int j = 2;
            while(i * j <= n)
            {
                v[i * j] = false;
                j++;
            }
        }
    }
    for(int i = 2; i < n + 1; i++)
    {
        if(v[i])
            answer++;
    }
    return answer;
}