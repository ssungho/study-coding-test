using System;
/// <summary>
/// 정수 배열 num_list와 정수 n이 매개변수로 주어집니다. 
/// num_list를 다음 설명과 같이 2차원 배열로 바꿔 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class _2차원으로_만들기
{
    public int[,] solution(int[] num_list, int n)
    {
        int[,] answer = new int[num_list.Length / n, n];
        int cnt = 0;
        for (int i = 0; i < num_list.Length / n; i++)
        {
            for (int j = 0; j < n ; j++)
            {
                answer[i, j] = num_list[cnt];
                cnt++;
            }
        }

        return answer;
    }
}

