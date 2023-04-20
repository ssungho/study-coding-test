using System;
/// <summary>
/// 영어에선 a, e, i, o, u 다섯 가지 알파벳을 모음으로 분류합니다. 
/// 문자열 my_string이 매개변수로 주어질 때 모음을 제거한 문자열을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class 모음_제거
{
    public string solution(string my_string)
    {
        string answer = "";
        for (int i = 0; i < my_string.Length; i++)
        {
            if (my_string[i] != 'a' && my_string[i] != 'e' && my_string[i] != 'i' && my_string[i] != 'o' && my_string[i] != 'u')
                answer += my_string[i];
        }
        return answer;
    }
}

