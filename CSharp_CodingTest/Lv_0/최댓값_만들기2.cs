using System;
/// <summary>
/// 정수 배열 numbers가 매개변수로 주어집니다. 
/// numbers의 원소 중 두 개를 곱해 만들 수 있는 최댓값을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 최댓값_만들기2
{
    public int solution(int[] numbers)
    {
        int answer = 0;
        Array.Sort(numbers);
        return answer = numbers[0] * numbers[1] >= numbers[numbers.Length - 1] * numbers[numbers.Length - 2] ?
                 numbers[0] * numbers[1] : numbers[numbers.Length - 1] * numbers[numbers.Length - 2];
    }
    public int solution2(int[] numbers) // 다른 사람 풀이 Max활용..
    {
        int len = numbers.Length;
        Array.Sort(numbers);
        return Math.Max(numbers[0] * numbers[1], numbers[len - 2] * numbers[len - 1]);
    }
}

