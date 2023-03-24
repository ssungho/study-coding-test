using System;
/// <summary>
/// 정수 배열 array가 매개변수로 주어질 때, 가장 큰 수와 그 수의 인덱스를 담은 배열을 return 하도록 solution 함수를 완성해보세요
/// </summary>
internal class 가장_큰_수_찾기
{
    public int[] solution(int[] array)
    {
        int[] answer = new int[2];
        int max = int.MinValue;
        int maxIndex = 0;

        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
                maxIndex = i;
            }
        }
        answer[0] = max;
        answer[1] = maxIndex;
        return answer;
    }
}

