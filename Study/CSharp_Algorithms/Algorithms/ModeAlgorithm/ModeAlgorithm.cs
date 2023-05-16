// [?] 주어진 데이터에서 가장 많이 나타난 값
using System;

// 최빈값 알고리즘(Mode Algorithm): 점수 인덱스의 개수의 최댓값
class ModeAlgorithm
{
    static void Main()
    {
        // [1] Input
        int[] scores = { 1, 4, 3, 4, 5 }; // 0 ~ 5까지만 들어온다고 가정
        int N = scores.Length;
        int[] indexes = new int[5 + 1]; // 0 ~ 5까지 점수 인덱스의 개수 저장
        int max = int.MinValue;
        int mode = 0;

        // [2] Process: Data -> Index -> Count -> Max -> Mode
        for (int i = 0; i < N; i++)
        {
            indexes[scores[i]]++; // COUNT
        }
        for (int i = 0; i < indexes.Length; i++)
        {
            if (indexes[i] > max)
            {
                max = indexes[i]; // MAX
                mode = i;
            }
        }
        // [3] Output
        Console.WriteLine($"최빈값: {mode}은 {max}번 나타납니다.");
    }
}

