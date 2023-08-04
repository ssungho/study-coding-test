#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack <pair<int,int>> s;
    
    int N = prices.size();
    for (int i = 0; i < N; i++)
    {
        if(s.empty())
            s.push({prices[i],i});
        else
        {
            while(!s.empty() && prices[i] < s.top().first)
            {
                answer[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({prices[i],i});
        }
    }
    
    while(!s.empty())
    {
        int index = s.top().second;
        answer[index] = N - 1 - index;
        s.pop();
    }

    return answer;
}