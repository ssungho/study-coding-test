using System;
/// <summary>
/// 문자열 my_string과 문자 letter이 매개변수로 주어집니다. 
/// my_string에서 letter를 제거한 문자열을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 특정_문자_제거하기
{
    public string solution(string my_string, string letter)
    {
        string answer = "";
        string[] temp = my_string.Split(letter);
        for (int i = 0; i < temp.Length; i++)
        {
            if (temp[i] != letter)
                answer += temp[i];
        }
        return answer;
    }
    public string solution2(string my_string, string letter)
    {
        string answer = my_string.Replace(letter, ""); // letter을 ""로 대체한다. 즉 지운다.
        return answer;
    }
}

