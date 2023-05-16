using System;

namespace CSharp_CodingTest.lv_1
{
    internal class 짝수와_홀수
    {
        public string solution(int num)
        {
            string answer = "";
            if (num % 2 == 0)
            {
                answer += "Even";
            }
            else
                answer += "Odd";
            return answer;
        }
    }
}
