using System;
/// <summary>
/// 한 개 이상의 항의 합으로 이루어진 식을 다항식이라고 합니다. 
/// 다항식을 계산할 때는 동류항끼리 계산해 정리합니다. 
/// 덧셈으로 이루어진 다항식 polynomial이 매개변수로 주어질 때, 
/// 동류항끼리 더한 결괏값을 문자열로 return 하도록 solution 함수를 완성해보세요. 
/// 같은 식이라면 가장 짧은 수식을 return 합니다.
/// </summary>
internal class 다항식_더하기
{
    public string solution(string polynomial)
    {
        string answer = "";
        string[] strings = polynomial.Split(" + ");
        int x = 0;
        int c = 0;
        for (int i = 0; i < strings.Length; i++)
        {
            if (strings[i].Contains('x'))
            {
                if (strings[i] == "x")
                    x += 1;
                else
                    x += int.Parse(strings[i].Replace("x", ""));
            }
            else
                c += int.Parse(strings[i]);
        }
        if (x == 0)
            answer = c.ToString();
        if (x == 1)
            answer = "x + " + c.ToString();
        if (x != 0 && x != 1)
            answer = x.ToString() + "x + " + c.ToString();
        if (c == 0)
            answer = answer.Replace(" + 0", "");
        return answer;
    }
}

