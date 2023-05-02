using System;
using System.Collections.Generic;
using System.Linq;

namespace 제일_작은_수_제거하기
{
    public class Solution
    {
        public int[] solution(int[] arr)
        {
            List<int> list = new List<int>();
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] != arr.Min())
                    list.Add(arr[i]);
            }
            if (list.Count == 0)
                list.Add(-1);
            return list.ToArray();
        }
    }
}
