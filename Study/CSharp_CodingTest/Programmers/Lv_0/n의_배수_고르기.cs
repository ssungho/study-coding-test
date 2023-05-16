using System;
using System.Collections.Generic;
/// <summary>
/// 정수 n과 정수 배열 numlist가 매개변수로 주어질 때, 
/// numlist에서 n의 배수가 아닌 수들을 제거한 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class n의_배수_고르기
{
    public int[] solution(int n, int[] numlist)
    {
        List<int> list = new List<int>();
        for (int i = 0; i < numlist.Length; i++)
        {
            if (numlist[i] % n == 0)
                list.Add(numlist[i]);
        }
        return list.ToArray();
    }
}

