using Microsoft.VisualBasic;
using System;
/// <summary>
/// 삼각형의 세 변의 길이가 담긴 배열 sides이 매개변수로 주어집니다. 
/// 세 변으로 삼각형을 만들 수 있다면 1, 만들 수 없다면 2를 return하도록 solution 함수를 완성해주세요.
/// (조건) 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 합니다.
/// </summary>


internal class 삼각형의_완성조건1
{
    public int solution(int[] sides)
    {
        int answer = 0;
        // 가장 큰 변보다 다른 변들의 합이 커야 삼각형을 만들 수 있음
        int max = int.MinValue;
        int sum = 0;
        // 최댓값을 구함
        for (int i = 0; i < sides.Length; i++)
        {
            if (sides[i] > max)
                max = sides[i];
        }
        // 나머지의 합
        Array.Sort(sides);
        sum = sides[0] + sides[1];

        if (max < sum)
            answer = 1;
        else
            answer = 2;

        return answer;
    }

    public int Solution2(int[] sides) // from GPT #1 일반적인 코드
    {
        Array.Sort(sides);  // 세 변의 길이를 오름차순으로 정렬
        if (sides[0] + sides[1] > sides[2])  // 가장 짧은 두 변의 길이의 합이 가장 긴 변의 길이보다 크다면
        {
            return 1;  // 삼각형을 만들 수 있음
        }
        else
        {
            return 0;  // 삼각형을 만들 수 없음
        }
    }

    public int Solution3(int[] sides) // from GPT #2 가독성 높인 코드
    {
        Array.Sort(sides);  // 세 변의 길이를 오름차순으로 정렬
        int shortestSide = sides[0];
        int middleSide = sides[1];
        int longestSide = sides[2];

        bool canMakeTriangle = shortestSide + middleSide > longestSide;

        return canMakeTriangle ? 1 : 0;  // 삼항 연산자를 사용하여 1 또는 0을 반환
    }
}

