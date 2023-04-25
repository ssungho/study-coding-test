using System;

namespace 서울에서_김서방_찾기
{
    public class Solution
    {
        public string solution(string[] seoul)
        {
            int x = 0;
            foreach (string s in seoul) 
            {
                if (s == "Kim")
                    return new string($"김서방은 {x}에 있다");
                x++;
            }
            return null;
        }
    }
}
