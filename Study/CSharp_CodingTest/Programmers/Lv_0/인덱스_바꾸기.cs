using System;
/// <summary>
/// 문자열 my_string과 정수 num1, num2가 매개변수로 주어질 때,
/// my_string에서 인덱스 num1과 인덱스 num2에 해당하는 문자를 바꾼 문자열을 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class 인덱스_바꾸기
{
    // 문자열 길이만큼 반복하면서 인덱스(매개변수로 받은 값)에 교체.
    public string solution(string my_string, int num1, int num2)
    {
        string answer = "";
        for (int i = 0; i < my_string.Length; i++)
        {
            if(i == num1)
                answer += my_string[num2];
            else if (i == num2)
                answer+= my_string[num1];
            else
            answer += my_string[i];
        }

        return answer;
    }
    // 문자열을 Char[]형태로 바꾼뒤, 위치 변경.
    public string Solution2(string my_string, int num1, int num2)
    {
        string answer = "";
        char[] ch = my_string.ToCharArray();

        ch[num1] = my_string[num2];
        ch[num2] = my_string[num1];

        answer = new string(ch);
        return answer;
    }
}

