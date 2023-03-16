using System;
using System.Runtime.CompilerServices;

/// <summary>
/// 외과의사 머쓱이는 응급실에 온 환자의 응급도를 기준으로 진료 순서를 정하려고 합니다. 
/// 정수 배열 emergency가 매개변수로 주어질 때,
/// 응급도가 높은 순서대로 진료 순서를 정한 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class 진료순서_구하기
{
    public int[] solution(int[] emergency)
    {
        int[] _emergency = new int[emergency.Length];
        Array.Copy(emergency, _emergency, emergency.Length);
        int[] answer = new int[emergency.Length];
        Array.Sort(_emergency); // 정렬

        for (int i = 0; i < emergency.Length; i++)
        {
            for (int j = 0; j < emergency.Length; j++)
            {
                if (emergency[i] == _emergency[j])
                    answer[i] = emergency.Length - j;
            }
        }
        return answer;
    }

    // 노가다로 풀었는데 사실 Rank알고리즘을 이용하면 쉽게 풀 수 있던 문제임..
    // C:\Users\Ash\Desktop\CSharp\CSharp_Algorithm\CSharp_Algorithms\Algorithms\RankAlgorithm\RankAlgorithm.cs
    // 저 cs을 확인하자..
}

