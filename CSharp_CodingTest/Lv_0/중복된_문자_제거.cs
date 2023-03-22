using System;
/// <summary>
/// 문자열 my_string이 매개변수로 주어집니다.
/// my_string에서 중복된 문자를 제거하고 하나의 문자만 남긴 문자열을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 중복된_문자_제거
{
    public string solution(string my_string)
    {
        string answer = "";
        for (int i = 0; i < my_string.Length; i++)
        {
            if(!answer.Contains(my_string[i]))
                answer += my_string[i];
        }
        return answer;
    }
}

