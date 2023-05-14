using System;

namespace 최대공약수와_최소공배수
{
    public class Solution
    {
        public int[] solution(int n, int m)
        {
            int[] answer = new int[2];
            
            for (int i = 1; i <= MathF.Min(n,m); i++)
                if(n % i == 0 && m % i == 0)
                    answer[0] = i;
                
            answer[1] = (n * m) / answer[0];

            return answer;
        }
    }
}
