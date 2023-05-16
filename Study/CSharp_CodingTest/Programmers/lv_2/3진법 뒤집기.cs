using System;

public class Solution
{
    public int solution(int n)
    {
        List<int> list = new List<int>();
        int answer = 0;
        int count = 1;
        
        while(n > 1)
        {
            list.Add(n % 3);
            n /= 3;
        }

        list.Reverse();

        for(int i = 0; i < list.Count; i++)
        {
            answer += list[i] * count;
            count *= 3;
        }

        return answer;
    }
}

