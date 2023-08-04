#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack <int> s;

    int len = prices.size();
    for (int i = 0; i < len; i++)
    {
        if(s.empty())
            s.push(i);
        else
        {
            while(!s.empty() && prices[i] < prices[s.top()])
            {
                answer[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        answer[s.top()] = len - (s.top() + 1);
        s.pop();
    }

    return answer;
}