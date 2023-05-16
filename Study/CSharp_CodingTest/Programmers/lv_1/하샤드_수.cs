using System;

namespace 하샤드_수
{
    public class Solution
    {
        public bool solution(int x)
        {
            int temp = 0;
            int num = x;
            while(x >= 1)
            {
                temp += (x % 10);
                x /= 10;
            }
            if (num % temp == 0)
                return true;
            else
                return false;
        }
    }
}
