using System;
using System.Collections.Generic;
/// <summary>
///my_string은 "3 + 5"처럼 문자열로 된 수식입니다.
///문자열 my_string이 매개변수로 주어질 때, 수식을 계산한 값을 return 하는 solution 함수를 완성해주세요.
/// </summary>
internal class 문자열_계산하기
{
    #region 첫시도
    /*
    public int solution(string my_string)
    {
        int answer = 0;
        string op = "";
        int cnt = 0;
        int[] temp = new int[2];

        for (int i = 0; i < my_string.Length; i++)
        {
            if (my_string[i] == ' ')
                continue;
            else if (my_string[i] == '+' || my_string[i] == '-')
                op += my_string[i];
            else
            {
                temp[cnt] = int.Parse(my_string[i].ToString());
                cnt++;
            }
        }
        if (op.Contains('+'))
            answer = temp[0] + temp[1];
        else
            answer = temp[0] - temp[1];

        return answer;
    }
    */
    #endregion
    public int solution(string my_string)
    {
        int answer = 0;
        int cnt = 0;
        List<char> operators = new List<char>();
        List<int> numbers = new List<int>();
        string temp = "";
        // 분배
        for (int i = 0; i < my_string.Length; i++)
        {
            if (my_string[i] != ' ')
            {
                if (my_string[i] == '+' || my_string[i] == '-')
                    operators.Add(my_string[i]);
                else
                    temp += my_string[i].ToString();
            }
            if ((my_string[i] == ' ' && temp != "") || (i == my_string.Length - 1))
            {
                numbers.Add(int.Parse(temp));
                temp = "";
            }
        }

        answer += numbers[0];
        for (int i = 1; i < numbers.Count; i++)
        {
            if (operators[cnt] == '+')
                answer += numbers[i];
            if (operators[cnt] == '-')
                answer -= numbers[i]; ;
            cnt++;
        }
        return answer;
    }
}

