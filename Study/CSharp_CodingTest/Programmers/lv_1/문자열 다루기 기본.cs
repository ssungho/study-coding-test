using System;
using System.Linq;

namespace 문자열_다루기_기본
{
    public class Solution
    {
        public bool solution(string s)
        {
            char[] num = new char[10] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
            if (s.Length == 4 || s.Length == 6)
            {
                for (int i = 0; i < s.Length; i++)
                {
                    if (!num.Contains(s[i]))
                        return false;
                }
            }
            else
                return false;
            return true;
        }
    }
}
