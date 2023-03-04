// [?] 주어진 데이터 중에서 가장 작은 값
// 최솟값 알고리즘(Min Algorithm): (주어진 범위 + 주어진 조건)의 자료들의 가장 작은 값

using System;
using System.Linq;
class MinAlgorithm
{
    static void Main()
    {
        // [1] Initialize
        int min = int.MaxValue; // 최솟값 알고리즘은 정수 형식의 데이터 중 가장 큰 값으로 초기화

        // [2] Input
        int[] numbers = { -2, 1, -3, -5, -9 };

        // [3] Process: MAX
        for (int i = 0; i < numbers.Length; i++)
        {
            if (numbers[i] < min)
            {
                min = numbers[i]; // MIN을 더 작은 값으로 할당 
            }
        }

        // [4] Output
        Console.WriteLine($"최솟값(식): {numbers.Min()}");
        Console.WriteLine($"최솟값(문): {min}");
    }
}