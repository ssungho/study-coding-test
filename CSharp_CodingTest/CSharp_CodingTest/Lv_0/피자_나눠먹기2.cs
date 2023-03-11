using System;
/// <summary>
/// 머쓱이네 피자가게는 피자를 여섯 조각으로 잘라 줍니다. 
/// 피자를 나눠먹을 사람의 수 n이 매개변수로 주어질 때,
/// n명이 주문한 피자를 남기지 않고 모두 같은 수의 피자 조각을 먹어야 한다면 
/// 최소 몇 판을 시켜야 하는지를 return 하도록 solution 함수를 완성해보세요.
/// </summary>
class 피자_나눠먹기2
{
    public class Solution
    {
        public int solution(int n) // n은 사람의 수
        {
            // [1] Input
            int need = 1; // 필요한 피자 개수
            int piece = need * 6;

            // [2] Process

            while (piece % n != 0) // 조각 % 사람 == 0 일때까지 반복
            {
                need++; // 피자 추가
                piece = need * 6; // 식에 쓰일 조각 초기화
            }

            // [3] Output
            return need;
        }
    }
}