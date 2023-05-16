// [?] 최대값과 최솟값을 제외한 나머지의 평균값을 구하는 프로그램
using System;

// 최댓값과 최솟값을 제외한 평균값 구하기
class AverageExceptionMaxAndMin
{
    static void Main()
    {
        // [1] Input
        int[] scores = { 10, 20, 30, 40, 50 };
        int max = int.MinValue; // MAX 해당 범위에서 가장 작은 값으로 초기화
        int min = int.MaxValue; // MIN 해당 범위에서 가장 큰 값으로 초기화
        int sum = 0; // SUM
        double avg = 0; // AVERAGE

        // [2] Process
        for (int i = 0; i < scores.Length; i++)
        {
            sum += scores[i]; // SUM
            if (max < scores[i])
                max = scores[i]; // MAX

            if (min > scores[i])
                min = scores[i]; // MIN
        }

        // [!] 최댓값과 최솟값을 제외한 평균값 구하기
        avg = (sum - max - min) / (double)(scores.Length - 2); // AVERAGE

        // [3] Output
        Console.WriteLine($"합계: {sum}, 최댓값: {max}, 최솟값: {min}");
        Console.WriteLine($"최댓값과 최솟값을 제외한 평균값: {avg:F2}");
    }
}

