using System;

internal class 치킨_쿠폰
{
    public int solution(int chicken)
    {
        int answer = 0; // 정답
        int coupon = chicken; // 쿠폰 ( 10개가 모이면 치킨 하나 + 쿠폰)

        while (coupon >= 10)
        {
            if(coupon >= 10)
            {
                answer += coupon / 10;
                chicken = coupon / 10;
                coupon = chicken + coupon % 10;
            }
        }
        return answer;
    }
}

