using System;

/// <summary>
/// 머쓱이네 옷가게는 10만 원 이상 사면 5%, 30만 원 이상 사면 10%, 50만 원 이상 사면 20%를 할인해줍니다.
/// 구매한 옷의 가격 price가 주어질 때, 지불해야 할 금액을 return 하도록 solution 함수를 완성해보세요.
/// </summary>

public class 옷가게_할인_받기
{
    public int solution(int price)
    {
        // [1] input
        int answer = 0;

        // [2] process
        if (price < 100000) 
        {
            answer = price;
        }
        if(price >= 100000 && 300000 > price)
        {
            answer = (int)(price - price * 0.05);
        }
        if (price >= 300000 && 500000 > price)
        {
            answer = (int)(price - price * 0.1);
        }
        if (price >= 500000)
        {
            answer = (int)(price - price * 0.2);
        }

        // [3] output
        return answer;
    }
    public class Solution2 // gpt
    {
        public int solution(int price)
        {
            int discount = 0;

            if (price >= 500000)
            {
                discount = 20;
            }
            else if (price >= 300000)
            {
                discount = 10;
            }
            else if (price >= 100000)
            {
                discount = 5;
            }

            return (int)(price - price * discount * 0.01);
        }
    }
}

