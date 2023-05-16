using System;
/// <summary>
/// 어떤 세균은 1시간에 두배만큼 증식한다고 합니다. 
/// 처음 세균의 마리수 n과 경과한 시간 t가 매개변수로 주어질 때 t시간 후 세균의 수를 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 세균_증식
{
    public int solution(int n, int t)
    {
        int answer = 0;
        int time = 1;
        for (int i = 1; i <= t; i++)
        {
            time *= 2;
        }
        answer = n * time;

        return answer;
    }
}

