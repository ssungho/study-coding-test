using System;
/// <summary>
/// i팩토리얼 (i!)은 1부터 i까지 정수의 곱을 의미합니다. 
/// 예를들어 5! = 5 * 4 * 3 * 2 * 1 = 120 입니다. 
/// 정수 n이 주어질 때 다음 조건을 만족하는 가장 큰 정수 i를 return 하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 팩토리얼
{
    public int solution(int n)
    {
        int answer = 0;
        for (int i = 1; i <= 10; i++)
        {
            // 만약 입력값(n)이 i 팩토리얼과 같다면 answer는 i가 된다.
            if(n == factorial(i))
            {
                answer = i;
            }
            // 만약 입력값(n)이 i팩토리얼보다 작다면 answer는 (i - 1)이 된다.
            if(n < factorial(i))
            {
                answer = i - 1;
                break;
            }
        }
        return answer;
    }

    // 팩토리얼을 구하는 함수
    public int factorial(int n)
    {
        int num = 1;
        for (int i = 1; i <= n; i++)
        {
            num *= i;
        }
        return num;
    }
}

