// [?] 원본 데이터 중에서 대상 데이터와 가장 가까운 값
using System;

// 근삿값 알고리즘(Near Algorithm): 차이값의 절댓값의 최솟값
#region 내 생각
/*
class NearAlgorithm
{
    static void Main()
    {
        // [1] Initialize
        int min = int.MaxValue; // 최솟값이 담길 그릇
        int minNum = 0;
        // [2] Input
        int[] numbers = { 10, 20, 30, 27, 17 };
        int target = 25;
        

        // [3] Process
        for (int i = 0; i < numbers.Length; i++) 
        {
            int temp = Math.Abs(target - numbers[i]);
            if (min > temp)
            {
                min = temp;
                minNum = numbers[i];
            }
        }
        // [4] Output
        Console.WriteLine($"{target}와 가장 가까운 값: {minNum}(차이: {min})");
    }
}
*/
#endregion
class NearAlgorithm
{
    static void Main()
    {
        // [0] 절댓값 구하기 로컬 함수
        int Abs(int num) => (num < 0) ? -num : num;

        // [1] Initialize
        int min = int.MaxValue; // 최솟값이 담길 그릇

        // [2] Input
        Console.Write("숫자를 입력하세요. : ");
        int[] numbers = { 10, 20, 30, 27, 17 };
        int target = Convert.ToInt32(Console.ReadLine());
        int near = default; // 가까운 값을 담을 그릇

        // [3] Process: NEAR
        for (int i = 0; i < numbers.Length; i++)
        {
            int abs = Abs(numbers[i] - target); // 차이값의 절댓값
            if (abs < min)
            {
                min = abs; // MIN 최솟값 알고리즘
                near = numbers[i]; // NEAR: 차이값의 절댓값의 최솟값일 때의 값
            }
        }

        // [4] Output
        Console.WriteLine($"{target}와 가장 가까운 값: {near}(차이: {min})");
    }
    // 람다식 구현
    // var minimum = numbers.Min(m => Math.Abs(m - target)); // 차이값의 최솟값
    // var closest = numbers.First(n => Math.Abs(n - target) == minimum); // 근삿값
    // Console.WriteLine($"{target}와 가장 가까운 값: {closest}(차이: {minimum})");
}

