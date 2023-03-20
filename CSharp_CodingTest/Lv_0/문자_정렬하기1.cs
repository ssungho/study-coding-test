using System;
using System.Collections.Immutable;
/// <summary>
/// 문자열 my_string이 매개변수로 주어질 때, 
/// my_string 안에 있는 숫자만 골라 오름차순 정렬한 리스트를 return 하도록 solution 함수를 작성해보세요.
/// </summary>
internal class 문자_정렬하기1
{
    public int[] solution(string my_string)
    {
        List<int> num = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        for (int i = 0; i < my_string.Length; i++)
        {
            if (num.Contains(Convert.ToInt32(my_string[i])))
            {
                num.Add(my_string[i]);
            }
        }
        num.Sort();
        return num.ToArray();
    }
}

