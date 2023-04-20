using System;
/// <summary>
/// 정수 n이 매개변수로 주어질 때 n의 각 자리 숫자의 합을 return하도록 solution 함수를 완성해주세요
/// </summary>
internal class 자릿수_더하기
{
    public int solution(int n)
    {
        int answer = 0;
        while(n >= 1)
        {
            // 1의자리부터 검출
            if (n % 10 != 0)
                answer += n % 10;
            // 1의자리를 검출했다면 10의자리수를 검출하기위해 10을 나눔.. 반복
            n = n / 10;
        }
        return answer;
    }
}