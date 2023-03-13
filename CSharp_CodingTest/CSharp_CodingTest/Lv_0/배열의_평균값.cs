using System;
/// <summary>
/// 정수 배열 numbers가 매개변수로 주어집니다.
/// numbers의 원소의 평균값을 return하도록 solution 함수를 완성해주세요.
/// </summary>
public class 배열의_평균값
{
    public double solution(int[] _numbers)
    {
        int[] numbers = _numbers;
        int sum = 0;
        double answer = 0;

        for (int i = 0; i < numbers.Length; i++)
            sum += numbers[i];

        return answer = (double)sum / numbers.Length;
    }
}