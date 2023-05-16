using System;
/// <summary>
/// 문자열 my_string이 매개변수로 주어집니다. 
/// my_string안의 모든 자연수들의 합을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class 숨어있는_숫자의_덧셈1
{
    public int solution(string my_string)
    {
        int answer = 0;
        // 입력값, 입력값만큼 반복, 숫자면 정답에 더한다.
        for (int i = 0; i < my_string.Length; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (my_string[i].ToString() == j.ToString())
                    answer += j;
            }
        }
        return answer;
    }
}

