using System;
using System.Linq;
/// <summary>
/// 선분 세 개로 삼각형을 만들기 위해서는 다음과 같은 조건을 만족해야 합니다.
///     거정 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 합니다.
/// 삼각형의 두 변의 길이가 담긴 배열 sides이 매개변수로 주어집니다.
/// 나머지 한 변이 될 수 있는 정수의 개수를 return 하도록 siolution 함수를 완성해 주세요.
/// </summary>
internal class 삼각형_완성조건2
{
    public int solution(int[] sides)
    {
        int answer = 0;
        int max = sides.Max();
        int min = sides.Min();
        for (int i = 0; i < max + min; i++)
        {
            if (min + i > max && i <= max)
                answer++;
            if (i < max + min && i > max)
                answer++;
        }
        return answer;
    }
}

