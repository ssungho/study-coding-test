#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = -1;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i : scoville) 
    {
        pq.push(i);
    }
    
    int mix_count = 0;
    
    while (!pq.empty()) 
    {
        int first = pq.top();
        pq.pop();
        
        if (first >= K)
        {
            answer = mix_count;
            break;
        }
        else if (pq.empty()) 
        {
            break;
        }
        
        int second = pq.top();
        pq.pop();
        
        int mix = first + second * 2;
        pq.push(mix);
        
        mix_count++;
    }
    
    return answer;
}