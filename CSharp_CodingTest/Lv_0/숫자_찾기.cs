using System;
/// <summary>
/// 정수 num과 k가 매개변수로 주어질 때, num을 이루는 숫자 중에 k가 있으면 
/// num의 그 숫자가 있는 자리수를 return하고 없으면 -1을 return하도록 solution 함수를 완성해보세요.
/// </summary>

// O(n)의 n은 num의 길이다.

internal class 숫자_찾기
{
    public int solution(int num, int k)
    {
        int answer = -1;
        int N = num.ToString().Length; // 숫자의 길이 6 하지만 인덱스는 0부터 5까지
        for (int i = 0; i < N; i++)
        {
            // 만약 i+1의 자릿수가 k라면,
            if (num % 10 == k)
                // 정답은 숫자의 길이 - i
                // 왜냐면 숫자를 앞자리부터 세기 때문. 
                answer = N - i;
            
            // 숫자의 자릿수를 조정
            num /= 10;
        }
        return answer;
    }
}

