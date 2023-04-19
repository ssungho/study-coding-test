using System;

namespace 정수_제곱근_판별
{
    public class Solution
    {
        public long solution(long n)
        {
            // 양의 정수를 나타낼 변수
            long num = 1;
            // num이 n의 제곱근보다 커질때까지 반복
            while(num <= Math.Sqrt(n))
            {
                // 반환 조건
                if (num == Math.Sqrt(n))
                    return (num + 1) * (num + 1);
                // 카운트
                else
                    num++;
            }
            // 답이 없다면
            return -1;
        }
    }
}
