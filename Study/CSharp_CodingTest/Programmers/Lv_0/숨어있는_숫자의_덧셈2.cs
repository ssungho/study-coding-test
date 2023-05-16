using System;
/// <summary>
/// 문자열 my_string이 매개변수로 주어집니다. 
/// my_string은 소문자, 대문자, 자연수로만 구성되어있습니다. 
/// my_string안의 자연수들의 합을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 숨어있는_숫자의_덧셈2
{
    public int solution(string my_string)
    {
        int answer = 0;
        string temp = "";
        string nums = "0123456789";
        for (int i = 0; i < my_string.Length; i++)
        {
            if (nums.Contains((my_string[i])))
            {
                temp += my_string[i];
                if(i == my_string.Length - 1)
                    answer += int.Parse(temp);
            }
            else
            {
                if (temp == "")
                    continue;
                answer += int.Parse(temp);
                temp = "";
            }
        }
        return answer;
    }
}

