using System;
/// <summary>
/// 머쓱이는 행운의 숫자 7을 가장 좋아합니다. 
/// 정수 배열 array가 매개변수로 주어질 때, 7이 총 몇 개 있는지 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class _7의_배수
{
    public int solution(int[] array)
    {
        int answer = 0;
        for (int i = 0; i < array.Length; i++)
        {
            while (array[i] > 0)
            {
                if (array[i] % 10 == 7)
                {
                    answer++;
                }
                array[i] = array[i] / 10;
            }
        }
        return answer;
    }
}

