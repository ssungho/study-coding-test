using System;
namespace 최댓값과_최솟값
{
    public class Solution
    {
        public string solution(string s)
        {
            int min = int.MaxValue;
            int max = int.MinValue;
            string temp = "";
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == ' ' || i == s.Length - 1)
                {
                    if (i == s.Length - 1)
                        temp += s[i];

                    if (int.Parse(temp) >= max)
                        max = int.Parse(temp);

                    if (int.Parse(temp) <= min)
                        min = int.Parse(temp);

                    temp = "";
                }
                else
                    temp += s[i];
            }
            return new string(min + " " + max);
        }
    }
}
