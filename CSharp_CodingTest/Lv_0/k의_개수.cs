using System;
using System.ComponentModel;
/// <summary>
/// 1부터 13까지의 수에서, 1은 1, 10, 11, 12, 13 이렇게 총 6번 등장합니다. 
/// 정수 i, j, k가 매개변수로 주어질 때, i부터 j까지 k가 몇 번 등장하는지 return 하도록 solution 함수를 완성해주세요.
/// </summary>
internal class k의_개수
{
    public int solution(int i, int j, int k)
    {
        int answer = 0;
        for(int q = i; q < j; q++)
        {
            while(q > 10)
            {
                if (q % 10 == k)
                    answer++;
                q = (int) q / 10;
            }
        }
        return answer;
    }
    public int solution2(int i, int j, int k)
    {
        int answer = 0;
        while (i <= j)
        {
            string x = i.ToString();
            for (int q = 0; q < x.Length; q++)
            {
                if (x[q].ToString() == k.ToString())
                    answer++;
            }
            i++;
        }
        return answer;
    }
}

