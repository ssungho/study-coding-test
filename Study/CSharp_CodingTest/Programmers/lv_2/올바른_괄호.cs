using System;

namespace 올바른_괄호
{
    public class Solution
    {
        public bool solution(string s)
        {
            Stack<char> stack = new Stack<char>();
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '(')
                    stack.Push(s[i]); // stack.push('('); 문자 바꿔서 효율성2 통과..;
                else
                {
                    if(stack.Count == 0)
                        return false;
                    
                    stack.Pop();
                }
            }

            if (stack.Count > 0)
                return false;
            else
                return true;
        }
    }
}
