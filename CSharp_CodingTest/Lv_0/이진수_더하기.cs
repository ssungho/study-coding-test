using System;
/// <summary>
/// 이진수를 의미하는 두 개의 문자열 bin1과 bin2가 매개변수로 주어질 때, 
/// 두 이진수의 합을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 이진수_더하기
{
    public string solution(string bin1, string bin2)
    {
        string answer = Convert.ToString(Convert.ToInt32(bin1, 2) + Convert.ToInt32(bin2, 2), 2);
        return answer;
    }
}

