#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    int answer = 0;
    
    queue<long> q1, q2;
    
    long total_sum = 0;
    long q1_sum = 0;
    long q2_sum = 0;
    
    for (int i = 0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        q1_sum += queue1[i];        
        q2_sum += queue2[i];
    }
    
    total_sum = q1_sum + q2_sum;
    
    if (total_sum % 2) return -1;
    
    while (q1.size() > 0 && q2.size() > 0)
    {       
        if (queue1.size() * 3 <= answer)
        {
            return -1;
        }
        
        if (q1_sum > q2_sum) 
        {
            int temp = q1.front();
            q2_sum += temp;
            q1_sum -= temp;
            q1.pop();
            q2.push(temp);
            answer++;
        }
        else if (q1_sum < q2_sum)
        {
            int temp = q2.front();
            q1_sum += temp;
            q2_sum -= temp;
            q2.pop();
            q1.push(temp);
            answer++;
        }
        else if (q1_sum == q2_sum)
        {
            return answer;
        }
    }
    
    if (q1_sum == q2_sum) 
    {
        return answer;
    }
    
    return -1;
}