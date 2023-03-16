using System;
using System.Collections.Generic;
/// <summary>
/// 정수 배열 numbers와 정수 num1, num2가 매개변수로 주어질 때, 
/// numbers의 num1번 째 인덱스부터 num2번째 인덱스까지 자른 정수 배열을 return 하도록 solution 함수를 완성해보세요.
/// </summary>

internal class 배열_자르기
{
    public int[] solution(int[] numbers, int num1, int num2)
    {
        List<int> list = new List<int>();

        for (int i = num1; i <= num2; i++)
        {
            list.Add(numbers[num1++]);
        }
        
        int[] answer = list.ToArray();
        return answer;
    }

    public int[] Solution2(int[] numbers, int num1, int num2)
    {
        int length = num2 - num1 + 1;
        int[] result = new int[length];

        for (int i = 0; i < length; i++)
        {
            int index = num1 + i;
            result[i] = numbers[index];
        }

        return result;
    }
}

