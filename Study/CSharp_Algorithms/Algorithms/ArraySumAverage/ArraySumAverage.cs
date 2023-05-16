// [?] 2차원 배열을 이용하여 점수의 합계와 평균을 구하기
class ArraySumAverage
{
    static void Main()
    {
        // [1] Input
        int[,] scores =
        {// {국어, 영어, 합계, 평균}
            { 90, 100, 0, 0 },
            { 80, 90, 0, 0 },
            { 100, 80, 0, 0 }
        };
        // [2] Process
        for (int i = 0; i < 3; i++)
        {
            scores[i, 2] = scores[i, 0] + scores[i, 1]; // SUM
            scores[i, 3] = scores[i, 2] / 2; // AVERAGE
        }
        // [3] Output
        Console.WriteLine("국어 영어 합계 평균");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Console.Write($"{scores[i, j], 4}");
            }
            Console.WriteLine();
        }
    }

}

