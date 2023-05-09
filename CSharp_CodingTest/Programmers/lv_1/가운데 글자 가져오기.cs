using System;

namespace 가운데_글자_가져오기
{
    public class Solution
    {
        public string solution(string s)
        {
            string answer = "";
            if (s.Length % 2 == 0)
            {
                answer += s[s.Length / 2 - 1];
                answer += s[s.Length / 2];
            }
            else
            {
                answer += s[s.Length / 2];
            }
            return answer;
        }
    }
}
