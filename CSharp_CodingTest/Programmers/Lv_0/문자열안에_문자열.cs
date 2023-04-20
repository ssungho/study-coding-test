using System;
/// <summary>
/// 문자열 str1, str2가 매개변수로 주어집니다. 
/// str1 안에 str2가 있다면 1을 없다면 2를 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 문자열안에_문자열
{
    public int solution(string str1, string str2)
    {
        int answer = 0;
        if(str1.Contains(str2))
            answer = 1;
        else
            answer= 2;
        return answer;
    }
}

