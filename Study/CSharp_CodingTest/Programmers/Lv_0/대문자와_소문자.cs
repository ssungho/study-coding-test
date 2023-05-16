using System;
using System.Globalization;
/// <summary>
/// 문자열 my_string이 매개변수로 주어질 때, 
/// 대문자는 소문자로 소문자는 대문자로 변환한 문자열을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 대문자와_소문자
{
    // char.IsLower, char.IsUpper을 사용해서 문자를 소문자인지 대문자인지 확인한 후 소문자라면 대문자로 대문자라면 소문자로 변환.
    public string solution(string my_string)
    {
        string answer = "";
        for (int i = 0; i < my_string.Length; i++)
        {
            if (char.IsLower(my_string[i]) == true) 
                answer += my_string[i].ToString().ToUpper();
            else
                answer += my_string[i].ToString().ToLower();
        }
        return answer;
    }
    // AZ까지 대문자 문자열을 생성후 여기에 포함된다면, 소문자로 바꾸고, 그렇지 않다면 대문자로 바꾸는 알고리즘.
    public string solution2(string my_string)
    {
        string AZ = "QWERTYUIOPASDFGHJKLZXCVBNM";
        string answer = "";
        for (int i = 0; i < my_string.Length; i++)
        {
            if (AZ.Contains(my_string[i]))
                answer += my_string[i].ToString().ToLower();
            else
                answer += my_string[i].ToString().ToUpper();
        }
        return answer;
    }
}

