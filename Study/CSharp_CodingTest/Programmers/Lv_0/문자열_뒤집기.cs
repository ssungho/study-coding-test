using System;
/// <summary>
/// 문자열 my_string이 매개변수로 주어집니다. 
/// my_string을 거꾸로 뒤집은 문자열을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 문자열_뒤집기
{
    public string solution(string my_string)
    {
        string answer = "";
        for (int i = 0; i < my_string.Length; i++)
        {
            string temp = my_string.Substring(my_string.Length - 1 - i, 1);
            answer += temp;
        }
        return answer;
    }

    public string solution2(string my_string)  // string의 Reverse()함수와 Toarray()함수를 이용
    {
        
        string answer = new string(my_string.Reverse().ToArray());
        return answer;
    }
}
