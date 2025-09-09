#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = -1;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int mix_count = 0;
    
    while (pq.size() >= 2) 
    {
        int first = pq.top();
        pq.pop();
        
        if (first >= K)
        {
            answer = mix_count;
            break;
        }
        
        int second = pq.top();
        pq.pop();
        
        int mix = first + second * 2;
        pq.push(mix);
        
        mix_count++;
    }
    
    if (pq.size() == 1 && pq.top() >= K) {
        answer = mix_count;
    }
    
    return answer;
}