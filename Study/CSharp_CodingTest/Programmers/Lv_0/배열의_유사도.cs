using System;
/// <summary>
/// 두 배열이 얼마나 유사한지 확인해보려고 합니다. 
/// 문자열 배열 s1과 s2가 주어질 때 같은 원소의 개수를 return하도록 solution 함수를 완성해주세요
/// </summary>
internal class 배열의_유사도
{
    public int solution(string[] s1, string[] s2)
    {
        int answer = 0;

        for (int i = 0; i < s1.Length; i++)
        {
            for (int j = 0; j < s2.Length; j++)
            {
                if (s1[i] == s2[j])
                    answer++;
            }
        }
        return answer;
    }
}

