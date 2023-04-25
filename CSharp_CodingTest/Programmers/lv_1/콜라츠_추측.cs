using System;

namespace 콜라츠_추측
{
    public class Solution
    {
        public int solution(int num)
        {
            int cnt = 0;
            while (cnt < 500)
            {
                if (num == 1)
                    return cnt;
                if (num % 2 == 0)
                    num = num / 2;
                else if (num % 2 == 1)
                    num = num * 3 + 1;
                cnt++;
            }
            return -1;
        }
    }
}
