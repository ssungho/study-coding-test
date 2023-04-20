using System;
/// <summary>
/// 정수가 담긴 배열 numbers와 문자열 direction가 매개변수로 주어집니다. 
/// 배열 numbers의 원소를 direction방향으로 한 칸씩 회전시킨 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class 배열_회전시키기
{
    public int[] solution(int[] numbers, string direction)
    {
        int[] answer = new int[numbers.Length];
        if (direction == "right") 
        {
            for (int i = 0; i < numbers.Length; i++)
            {
                if (i == 0)
                    answer[i] = numbers[numbers.Length - 1];
                else
                    answer[i] = numbers[i - 1];
            }
        }
        if (direction == "left")
        {
            for (int i = 0; i < numbers.Length; i++)
            {
                if (i == numbers.Length - 1)
                    answer[i] = numbers[0];
                else
                    answer[i] = numbers[i + 1];
            }
        }

        return answer;
    }
}

