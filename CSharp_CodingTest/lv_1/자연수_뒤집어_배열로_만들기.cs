using System;
using System.Collections.Generic;

namespace 자연수_뒤집어_배열로_만들기
{
    public class Solution
    {
        public int[] solution(long n)
        {
            List<int> nums = new List<int>();
            
            while(n >= 1)
            {
                long temp = n % 10;
                nums.Add((int) temp);
                n /= 10;
            }

            return nums.ToArray();
        }
    }
}
