using System;
/// <summary>
/// 머쓱이네 피자가게는 피자를 일곱 조각으로 잘라 줍니다.
/// 피자를 나눠먹을 사람의 수 n이 주어질 때,
/// 모든 사람이 피자를 한 조각 이상 먹기 위해 필요한 피자의 수를
/// return 하는 solution 함수를 완성해보세요.
/// </summary>

class 피자_나눠먹기1
{
    public class Solution
    {
        public int solution(int n) // n은 사람의 수
        {
            // [1] Input
            int need = 0; // 필요한 피자 개수
            int piece = 0; // 피자 조각

            // [2] Process
            // 피자 조각이 사람 수보다 작다면
            while(piece < n)
            {
                need++; // 피자 +1
                piece = need * 7; // 조각 초기화
            }

            // [3] Output
            return need;
        }
    }
}

