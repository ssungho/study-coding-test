using System;
using System.Collections.Generic;

public class 짝수는_싫어요
{
    public int[] solution(int n)
    {
        int[] answer = new int[] { };
        List<int> list = new List<int>();

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
                list.Add(i);
        }
        if (n % 2 == 1)
            list.Add(n);
        answer = list.ToArray();

        return answer;
    }
}