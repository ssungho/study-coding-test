// [?] 정수 하나를 입력 받아, 2부터 해당 수까지 존재하는 모든 소수를 찾아서 출력
// 예: 2 ~ 20까지의 정수 : 2, 3, 5, 7 -> 4개

class PrimeNumberCount
{
    static void Main()
    {
        // [1] Input
        var count = 0; // 소수 개수
        var sw = true; // 소수인지 확인하는 스위치 변수
        var number = 0; // 2 ~ number까지의 수 중 소수를 구함
        Console.Write("수 입력 : _\b");
        number = Convert.ToInt32(Console.ReadLine());

        // [2] Process
        for (int i = 2; i <= number; i++) // 2부터 n까지 반복하면서 소수 판별
        {
            sw = true; // 일단 모든 반복마다 소수로 놓고 시작

            // 2부터 현재 수(i) -1까지 나누었을 때 너누어 떨어지면 소수가 아님
            for(int j = 2; j < i; j++)
            {
                if(i % j == 0)
                {
                    sw = false;
                    break;
                }
            }

            if(sw == true)
            {
                Console.Write($"{i}\t");
                count++; // Count

                if(count % 5 == 0) 
                {
                    Console.WriteLine(); // 줄바꿈
                }
            }
        }

        // [3] Ouput
        Console.WriteLine($"2부터 {number}까지의 소수의 개수 : {count}");
    }
}
