// [?] 전체 학생 평균 이상의 성적인 학생의 수를 구하는 프로그램
using System;

// 평균 이상 학생: 평균(합계, 개수) -> 개수
class AverageCount
{
    static void Main()
    {
        // [1] Input
        int[] scores = { 100, 90, 80, 70, 60 };
        int sum = 0; // 합계
        int count = 0; // 개수
        float avg = 0f; // 평균
        int resultCount = 0; // 평균 이상의 학생의 수

        // [2] Process: SUM, COUNT, AVERAGE => COUNT
        // [2][1] 평균
        for (int i = 0;i < scores.Length; i++) 
        {
            sum += scores[i]; // 합계
            count++; // 개수
        }
        if(sum != 0 && count != 0)
        {
            avg = sum / (float)count; // 평균
        }

        // [2][2] 평균 이상 학생 수
        for (int i = 0; i < scores.Length; i++)
        {
            if (scores[i] >= avg) // 평균 이상의 학생의 수
            {
                resultCount++; // 개수
            }
        }
        // [3] Output
        Console.WriteLine($"평균({avg}점) 이상의 점수를 받은 학생수: {resultCount}명");
    }
}