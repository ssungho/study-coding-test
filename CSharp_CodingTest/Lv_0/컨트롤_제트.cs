using System;
/// <summary>
/// 숫자와 "Z"가 공백으로 구분되어 담긴 문자열이 주어집니다. 
/// 문자열에 있는 숫자를 차례대로 더하려고 합니다. 
/// 이 때 "Z"가 나오면 바로 전에 더했던 숫자를 뺀다는 뜻입니다. 
/// 숫자와 "Z"로 이루어진 문자열 s가 주어질 때, 
/// 머쓱이가 구한 값을 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class 컨트롤_제트
{
    public int solution(string s)
    {
        int answer = 0;
        List<int> list = new List<int>();
        string temp = "";

        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == ' ')
            {
                list.Add(int.Parse(temp));
                temp = "";
            }
            if (s[i] == 'Z')
            {
                list.Remove(list[list.Count - 1]);
                temp = "";
                i++;
            }
            else
                temp += s[i];

            if (i == s.Length - 1)
                list.Add(int.Parse(temp));
            
        }
        for (int i = 0; i < list.Count; i++)
        {
            answer += list[i];
        }
        return answer;
    }

    public int solution2(string s) // 다른 사람 코드
    {
        int answer = 0;
        var list = s.Split(' ').ToList();

        while (list.Contains("Z"))
        {
            list.RemoveRange(list.IndexOf("Z") - 1, 2);
        }

        answer = list.Sum(x => Convert.ToInt32(x));

        return answer;
    }
}

