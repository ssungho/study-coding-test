using System;
using System.Runtime.Intrinsics.X86;
/// <summary>
/// 문자열 my_str과 n이 매개변수로 주어질 때, 
/// my_str을 길이 n씩 잘라서 저장한 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 잘라서_배열로_저장하기
{
    public string[] solution(string my_str, int n)
    {
        string[] answer = my_str.Length % n == 0 ? new string[my_str.Length / n] : new string[my_str.Length / n + 1];
        int cnt = 0;
        for (int i = 0; i < my_str.Length / n; i++)
        {
            for (int j = cnt; j < n + cnt; j++)
                answer[i] += my_str[j];
            cnt += n;
        }
        while (cnt < my_str.Length)
        {
            answer[answer.Length - 1] += my_str[cnt];
            cnt++;
        }
        return answer;
    }
}