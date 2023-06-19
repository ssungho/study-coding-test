#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<int>lost_stu;
    vector<int>reserve_stu;

    answer += n;

    for (int i = 0; i < n + 1; i++)
    {
        lost_stu.push_back(0);
        reserve_stu.push_back(0);

        if (find(lost.begin(), lost.end(), i) != lost.end())
        {
            lost_stu[i] = 1;
            answer--;
        }

        if (find(reserve.begin(), reserve.end(), i) != reserve.end())
        {
            reserve_stu[i] = 1;
        }

        if(lost_stu[i] == 1 && reserve_stu[i] == 1)
        {
            lost_stu[i] = 0;
            reserve_stu[i] = 0;
            answer++;
        }
    }

    
    for (int i = 1; i < n + 1; i++)
    {
         if(lost_stu[i] == 1 && reserve_stu[i - 1] == 1)
        {
            reserve_stu[i - 1] = 0;
            lost_stu[i] = 0;
            answer++;
        }
        
        if(lost_stu[i] == 1 && reserve_stu[i + 1] == 1)
        {
            reserve_stu[i + 1] = 0;
            lost_stu[i] = 0;
            answer++;
        }
    }

    return answer;
}