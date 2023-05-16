using System;
using System.Collections.Immutable;
/// <summary>
/// 정수 배열 array와 정수 n이 매개변수로 주어질 때, 
/// array에 들어있는 정수 중 n과 가장 가까운 수를 return 하도록 
/// solution 함수를 완성해주세요.
/// </summary>


internal class 가까운_수
{
    public int solution(int[] array, int n)
    {
        int answer = 0;
        int near = int.MaxValue;
        Array.Sort(array);
        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] == n)
                return answer = n;
            // 만약 n - 배열의 숫자가 현재 값보다 더 작다면
            if(Math.Abs(n - array[i]) < near)
            {
                near = n - array[i];
                answer = array[i];
            }
        }
        return answer;
    }
}

