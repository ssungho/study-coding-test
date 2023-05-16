using System;
/// <summary>
/// 선분 3개가 평행하게 놓여 있습니다. 
/// 세 선분의 시작과 끝 좌표가 [[start, end], [start, end], [start, end]] 형태로 들어있는 2차원 배열 lines가 매개변수로 주어질 때, 
/// 두 개 이상의 선분이 겹치는 부분의 길이를 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class 겹치는_선분의_길이
{
    public int solution(int[,] lines)
    {
        int answer = 0;
        int[] ints = new int[200];
        for (int i = 0; i < lines.GetLength(0); i++)
        {
            for (int j = lines[i, 0] + 100; j < lines[i, 1] + 100; j++)
                ints[j]++;
        }
        for (int i = 0; i < 200; i++)
        {
            if(ints[i] > 1)
                answer++;
        }
        return answer;
    }
}

