using System;
using System.Collections.Generic;

namespace 나누어_떨어지는_숫자_배열
{
    public class Solution
    {
        public int[] solution(int[] arr, int divisor)
        {
            List<int> list = new List<int>();

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] % divisor == 0)
                    list.Add(arr[i]);
            }

            list.Sort();

            if (list.Count == 0)
                list.Add(-1);

            return list.ToArray();
        }
    }
}
