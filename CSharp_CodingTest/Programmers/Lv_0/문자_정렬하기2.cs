using System;
/// <summary>
/// 영어 대소문자로 이루어진 문자열 my_string이 매개변수로 주어질 때, 
/// my_string을 모두 소문자로 바꾸고 알파벳 순서대로 정렬한 문자열을 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class 문자_정렬하기2
{
    public string solution(string my_string)
    {
        string answer = "";
        List<char> chars = new List<char>();
        for (int i = 0; i < my_string.Length; i++)
        {
            chars.Add(char.ToLower(my_string[i]));
        }
        for (int i = 0; i < chars.Count; i++)
        {
            for (int j = i + 1; j < chars.Count; j++)
            {
                if ((int)chars[i] > (int)chars[j])
                {
                    char temp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = temp;
                }
            }
        }
        foreach (char c in chars)
        {
            answer += c;
        }
        return answer;
    }
}

