using System;
/// <summary>
/// 문자열 배열 strlist가 매개변수로 주어집니다.
/// strlist 각 원소의 길이를 담은 배열을 retrun하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 배열_원소의_길이
{
    public int[] solution(string[] strlist)
    {
        int[] answer = new int[strlist.Length];

        for (int i = 0; i < strlist.Length; i++)
        {
            answer[i] = strlist[i].Length;
        }
        return answer;
    }
}

