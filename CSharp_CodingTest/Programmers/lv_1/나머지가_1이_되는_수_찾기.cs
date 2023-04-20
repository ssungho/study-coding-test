using System;

namespace 나머지가_1이_되는_수_찾기
{
    public class Solution
    {
        public int solution(int n)
        {
            int cnt = 1;
            while (cnt < n)
            {
                if (n % cnt == 1)
                    return cnt;
                cnt++;
            }
            return cnt;
        }
    }
}
