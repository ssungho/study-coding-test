using System;
using System.Linq;
/// <summary>
/// 문자열 s가 매개변수로 주어집니다. 
/// s에서 한 번만 등장하는 문자를 사전 순으로 정렬한 문자열을 return 하도록 solution 함수를 완성해보세요.
/// 한 번만 등장하는 문자가 없을 경우 빈 문자열을 return 합니다.
/// </summary>
internal class 한번만_등장한_문자
{
    public string solution(string s)
    {
        string answer = "";
        for (int i = 0; i < s.Length; i++)
        {
            int cnt = 0;
            for (int j = 0; j < s.Length; j++)
            {
                if (s[i] == s[j])
                    cnt++;
            }
            if(cnt == 1)
                answer += s[i];
        }
        char[] chars = answer.ToCharArray();
        answer = string.Concat(chars.OrderBy(c => c));
        return answer;
    }
}

