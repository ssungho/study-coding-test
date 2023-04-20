using System;
/// <summary>
/// 소인수분해란 어떤 수를 소수들의 곱으로 표현하는 것입니다. 예를 들어 
/// 12를 소인수 분해하면 2 * 2 * 3 으로 나타낼 수 있습니다. 따라서 12의 소인수는 2와 3입니다. 
/// 자연수 n이 매개변수로 주어질 때 n의 소인수를 오름차순으로 담은 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class 소인수분해
{
    public int[] solution(int n)
    {
        
        List<int> PrimeNumList = new List<int>();
        List<int> numList = new List<int>();

        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if(i % j == 0)
                    cnt++;
            }
            if(cnt == 2)
                PrimeNumList.Add(i);
        }

        for (int i = 0; i < PrimeNumList.Count; i++)
        {
            if(n % PrimeNumList[i] == 0)
                numList.Add(PrimeNumList[i]);
        }

        int[] answer = numList.ToArray();
        return answer;
    }
    public static int[] Solution2(int n) // GPT 개선 코드
    {
        List<int> primeList = new List<int>();

        // Sieve of Eratosthenes to generate prime numbers
        bool[] isPrime = new bool[n + 1];
        for (int i = 2; i <= n; i++)
        {
            isPrime[i] = true;
        }
        for (int i = 2; i <= Math.Sqrt(n); i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
            {
                // Check if i is a prime factor of n
                while (n % i == 0)
                {
                    primeList.Add(i);
                    n /= i;
                }
            }
        }

        int[] answer = primeList.ToArray();
        return answer;
    }
}

