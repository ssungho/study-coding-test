// [?] 정렬되어 있는 데이터를 이진 검색을 사용하여 반씩 나눠서 검색
using System;
// 검색 알고리즘(SearchAlgorithm): 주어진 데이터에서 특정 데이터 찾기
class SearchAlgorithm
{
    static void Main()
    {
        Console.Write("검색할 숫자를 입력하세요: \b");

        // [1] Input
        int[] data = { 1, 3, 5, 7, 9 }; // 오름차순으로 정렬되었다고 가정
        int N = data.Length; // 의사코드
        int search = Convert.ToInt32(Console.ReadLine()); // 검색할 데이터
        bool flag = false; // 찾으면  true 찾지 못하면 false
        int index = -1; // 인덱스 변수: 찾은 위치

        // [2] Process: 이진 검색(Binary Search)
        int low = 0; // 낮은 인덱스
        int high = N - 1; // 높은 인덱스
        while(low <= high)
        {
            int mid = (low + high) / 2; // 중간 인덱스 구하기
            if (data[mid] == search)
            {
                flag = true;
                index = mid;
                break;
            }
             if (data[mid] > search)
            {
                high = mid - 1; // 찾을 데이터가 작으면 왼쪽 영역으로 이동
            }
            else
            {
                low = mid + 1; // 찾을 데이터가 크면 오른쪽 영역으로 이동
            }
        }

        // [3] Output
        if (flag)
        {
            Console.WriteLine($"{search}을(를) {index}위치에서 찾았습니다.");
        }
        else
            Console.WriteLine("찾지 못했습니다.");
    }
}

