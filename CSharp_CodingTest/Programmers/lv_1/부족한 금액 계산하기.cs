using System;

namespace 부족한_금액_계산하기
{
    class Solution
    {
        public long solution(int price, long money, int count)
        {
            int N = 1;
            while (N <= count)
            {
                money -= price * N;
                N++;
            }
            if (money < 0)
                return Math.Abs(money);
            else
                return 0;
        }
    }
}
