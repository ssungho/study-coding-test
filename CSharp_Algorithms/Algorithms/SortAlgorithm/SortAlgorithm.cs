// [?] 무작위 데이터를 순서대로 [오름차순|내림차순] 정렬 
// O(n^2)
using System;
// 정렬 알고리즘(Sort Algorithm): 가장 [작은|큰] 데이터를 왼쪽으로 순서대로 이동
class SortAlgorithm
{
    static void Main()
    {
        // [1] Input: Data Structure
        int[] data = { 3, 2, 1, 4, 5 };
        int N = data.Length; // 의사 코드(슈도코드) 형태로 알고리즘을 표현하기 위함

        // [2] process: Selection Sort(선택 정렬) 알고리즘
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (data[i] > data[j])
                {
                    int temp = data[i]; data[i] = data[j]; data[j] = temp;
                }
            }
        }

        // [3] Output
        for (int i = 0; i < N; i++)
        {
            Console.Write($"{data[i]}\t"); 
        }
        Console.WriteLine();
    }
}
