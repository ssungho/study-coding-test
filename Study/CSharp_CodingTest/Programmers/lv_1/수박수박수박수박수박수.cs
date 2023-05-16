using System;

namespace 수박수박수박수박수박수
{
    public class Solution
    {
        public string solution(int n)
        {
            string answer = "";
            int cnt = 1;
            while (cnt < n + 1)
            {
                if (cnt % 2 == 1)
                {
                    answer += '수';
                }
                else
                {
                    answer += '박';
                }
                cnt++;
            }
            return answer;
        }
    }
}
