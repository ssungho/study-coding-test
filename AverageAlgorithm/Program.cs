// [?] n명의 점수 중에서 80점 이상 95점 이하인 점수의 평균
// 평균 알고리즘(Average Algorithm): 주어진 범위에 주어진 조건에 해당하는 자료들의 평균
// [1] 입력: n명의 성적

class AverageAlgorithm
{
    static void Main()
    {
        // [1] 입력:
        int[] data = { 90, 65, 78, 50, 95 };
        int sum = 0; // 합계
        int cnt = 0; // 개수
        float avg = 0f; // 평균

        // [2] 처리:
        for (int i = 0; i < data.Length; i++)
        {
            if (data[i] >= 80 && data[i] <= 95)
            {
                sum += data[i]; // SUM
                cnt++; // COUNT
            }
        }
        avg = sum / (float)cnt; // 값

        // [3] 출력:
        Console.WriteLine($"80점 이상 95점 이하인 자료의 평균: {avg}");
    }

}
