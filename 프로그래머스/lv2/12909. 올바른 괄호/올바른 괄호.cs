using System;
using System.Collections.Generic;

public class Solution
{
    public bool solution(string s)
    {
        Stack<char> stack = new Stack<char>();
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == '(')
                stack.Push('(');
            else
            {
                if(stack.Count == 0)
                {
                    return false;
                }
                stack.Pop();
            }

        }
        if (stack.Count > 0)
            return false;
        else
            return true;

    }
}