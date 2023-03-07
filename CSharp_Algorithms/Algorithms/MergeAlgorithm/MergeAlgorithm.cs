// [?] 2개의 정수 배열 합치기
using System;
// 병합 알고리즘: 정렬된 두 개의 배열을 하나로 병합
class MergeAlgorithm
{
    static void Main()
    {
        // [1] Inupt
        int[] first = { 1, 3, 5 }; // 오름차순 정렬
        int[] second = { 2, 4 }; // 오름차순 정렬
        int M = first.Length;
        int N = second.Length;
        int[] merge = new int[M + N]; // 병합된 배열을 담을 그릇
        int i = 0; int j = 0; int k = 0;

        // [2] Process
        while (i < M && j < N)  // 둘중 하나라도 배열의 끝에 도착할 때 까지
        {
            if(first[i] <= second[j]) // 더 작은 값을 merge 배열에 저장
            {
                merge[k++] = first[i++];
            }
            else
            {
                merge[k++] = second[j++];
            }
        }
        while(i < M) // 첫 번째 배열이 끝까지 도달할 때 까지
        {
            merge[k++] = first[i++];
        }
        while(j< N) // 두 번째 배열이 끝까지 도달할 때 까지
        {
            merge[k++] = second[j++];
        }

        // [3] Output
        foreach( var m in merge)
        {
            Console.Write($"{m}\t");
        }
        Console.WriteLine();
    }
}

