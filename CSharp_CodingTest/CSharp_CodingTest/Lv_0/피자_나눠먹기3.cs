using System;
/// <summary>
/// 머쓱이네 피자가게는 피자를 두 조각에서 열 조각까지 원하는 조각 수로 잘라줍니다.
/// 피자 조각 수 slice와 피자를 먹는 사람의 수 n이 매개변수로 주어질 때,
/// n명의 사람이 최소 한 조각 이상 피자를 먹으려면 최소 몇 판의 피자를 시켜야하는지를
/// return 하도록 solution 함수를 완성해 보세요.
/// </summary>
class 피자_나눠먹기3
{
    public class Solution
    {
        public int solution(int slice, int n) // slice는 조각의 수, n은 사람의 수
        {
            // [1] Input
            int need = 0;
            int piece = need * slice; ; // 총 조각

            // [2] Process
            while (piece / n < 1)
            {
                need++;
                piece = need * slice;
            }
            
            // [3] Output
            return need;
        }
    }
    public class Solution2
    {
        public int solution(int slice, int n) // slice는 조각의 수, n은 사람의 수
        {
            return (int)((n - 1) / slice) + 1;
        }
    }
}