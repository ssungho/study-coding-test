using System;
/// <summary>
/// 정수가 들어 있는 배열 num_list가 매개변수로 주어집니다. 
/// num_list의 원소의 순서를 거꾸로 뒤집은 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>
public class 배열_뒤집기
{
    public int[] solution(int[] num_list)
    {
        int N = num_list.Length;
        int[] answer = new int[N];
        for (int i = 0; i < N; i++)
        {
            answer[num_list.Length -1 -i] = num_list[i];
        }

        return answer;
    }
}

