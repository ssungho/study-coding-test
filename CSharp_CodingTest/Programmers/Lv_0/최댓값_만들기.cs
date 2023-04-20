using System;
/// <summary>
/// 정수 배열 numbers가 매개변수로 주어집니다. 
/// numbers의 원소 중 두 개를 곱해 만들 수 있는 최댓값을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class 최댓값_만들기
{
    public int solution(int[] numbers)
    {
        int answer = 0;
        int max1 = int.MinValue;
        int max2 = int.MinValue;
        int index = 0;

        for (int i = 0; i < numbers.Length; i++)
        {
            if(numbers[i] > max1)
            {
                max1 = numbers[i];
                index = i;
            }
            
        }
        for (int i = 0; i < numbers.Length; i++)
        {
            if (i != index && numbers[i] > max2)
                max2 = numbers[i];
        }
        answer = max1 * max2;
        return answer;
    }

    public int solution2(int[] numbers) // array.sort를 이용해서 큰 수 두 개(뒤에서 두 개)를 곱한다.
    {
        int answer = 0;
        Array.Sort(numbers);
        answer = numbers[numbers.Length - 1] * numbers[numbers.Length - 2];

        return answer;
    }
}

