using System;
/// <summary>
/// 점 네 개의 좌표를 담은 이차원 배열  dots가 다음과 같이 매개변수로 주어집니다.
///     [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]
/// 주어진 네 개의 점을 두 개씩 이었을 때, 두 직선이 평행이 되는 경우가 있으면 1을 없으면 0을 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class 평행
{
    #region 테스트 케이스가 추가된 이후로 통과가 안된다. ( 12~17 실패 )
    /*
    public int solution(int[,] dots)
    {
        int answer = 0;
        float[] slope = new float[6];
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                slope[cnt] = ((float)(dots[i, 0] - dots[j, 0]) / (dots[i, 1] - dots[j, 1]));
                cnt++;
            }
        }
        for (int i = 0; i < slope.Length; i++)
        {
            for (int j = i + 1; j < slope.Length; j++)
            {
                if (slope[i] == slope[j])
                    return 1;
            }
        }
        return 0;
    }
    */
    #endregion
    #region 노가다 버전.. 
    public int solution(int[,] dots)
    {
        if ((float)(dots[0, 1] - dots[1, 1]) / (dots[0, 0] - dots[1, 0]) == (float)(dots[2, 1] - dots[3, 1]) / (dots[2, 0] - dots[3, 0]) ||
            (float)(dots[0, 1] - dots[2, 1]) / (dots[0, 0] - dots[2, 0]) == (float)(dots[1, 1] - dots[3, 1]) / (dots[1, 0] - dots[3, 0]) ||
            (float)(dots[0, 1] - dots[3, 1]) / (dots[0, 0] - dots[3, 0]) == (float)(dots[1, 1] - dots[2, 1]) / (dots[1, 0] - dots[2, 0]))
        { return 1; }

        return 0;
    }
    #endregion
}

