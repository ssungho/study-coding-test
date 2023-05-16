// 완전수(Perfect Number) : 자신을 제외한 약수의 합이 자신과 같은 수
// 예: 6 = 1 + 2 + 3
// 1부터 10,000까지의 완전수와 개수를 출력 -> number == 10,000일때 -> 4개

class PerfectNumber
{
    static void Main()
    {
        // [1] Iuput
        int number = 0; // 입력받을 숫자
        int sum = 0; // 약수의 합계
        int cnt = 0; // 완전수의 개수
        int max = 0; // 가장 큰 약수
        int rem = 0; // 나머지값 임시 보관

        Console.Write("수 입력: _\b");
        number = Convert.ToInt32(Console.ReadLine());

        // [2] Process
        for (int i = 1; i <= number; i++)
        {
            sum = 0; // 매 반복마다 0으로 초기화
            max = i / 2; // 모든 짝수를 2로 나누면 가장 큰 약수

            for (int j = 1; j <= max; j++)
            {
                rem = i - (i / j) * j; // 자신 / 약수
                if (rem == 0)
                {
                    sum += j; // 약수의 합계
                }
            }
            if (i == sum) // 자신 == 약수 => 완전수
            {
                Console.WriteLine($"완전수: {i}");
                cnt++; // 카운트 업데이트
            }
        }

        // [3] Output
        Console.WriteLine($"완전수의 개수 : {cnt}");

    }
}