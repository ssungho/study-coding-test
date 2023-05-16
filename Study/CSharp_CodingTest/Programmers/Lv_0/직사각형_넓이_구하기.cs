using System;
using System.ComponentModel;
using System.Runtime.Intrinsics.X86;
/// <summary>
/// 2차원 좌표 평면에 변이 축과 평행한 직사각형이 있습니다. 
/// 직사각형 네 꼭짓점의 좌표 [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]가 담겨있는 배열 dots가 매개변수로 주어질 때, 
/// 직사각형의 넓이를 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class 직사각형_넓이_구하기
{
    public int solution(int[,] dots)
    {
        int[] x = new int[2];
        int[] y = new int[2];
        int xCnt = 0;
        int yCnt = 0;
        for (int i = 0; i < 4; i++) // 꼭지점 개수
        {
            for (int j = i + 1; j < 4; j++)
            {
                if(dots[i, 0] == dots[j, 0])
                {
                    x[xCnt] = dots[i, 0];
                    xCnt++;
                }
                if (dots[i, 1] == dots[j, 1])
                {
                    y[yCnt] = dots[i, 1];
                    yCnt++;
                }
            }
        }
        int a = Math.Abs(x[0] - x[1]);
        int b = Math.Abs(y[0] - y[1]);

        int answer = a * b;
        return answer;
    }
}

