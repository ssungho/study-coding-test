using System;
using System.Linq;

namespace 문자열_내림차순으로_배치하기
{
    public class Solution
    {
        public string solution(string s)
        {
            string answer = "";
            char[] ch = s.ToArray();

            for (int i = 0; i < ch.Length - 1; i++)
            {
                for (int j = i + 1; j < ch.Length; j++)
                {
                    if (ch[i] <= ch[j])
                    {
                        char temp = ch[i];
                        ch[i] = ch[j];
                        ch[j] = temp;
                    }
                }
            }
            for (int i = 0; i < ch.Length; i++)
            {
                answer += ch[i];
            }
            return answer;
        }
    }
}