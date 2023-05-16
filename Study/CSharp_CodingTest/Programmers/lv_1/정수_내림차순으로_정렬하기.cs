using System;
using System.Collections.Generic;

namespace CSharp_CodingTest.Programmers.lv_1
{
    internal class 정수_내림차순으로_정렬하기
    {
        public class Solution
        {
            public long solution(long n)
            {
                long answer = 0;
                List<int> nums = new List<int>();
                while(n >= 1)
                {
                    nums.Add((int)(n % 10));
                    n /= 10;
                }
                nums.Sort();
                nums.Reverse();
                for (int i = 0; i < nums.Count; i++)
                {
                    answer+= nums[i];
                    if(i == nums.Count - 1)
                        return answer;
                    answer *= 10;
                }
                return answer;
            }
        }
    }
}
