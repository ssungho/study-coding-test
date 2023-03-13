using System;
/// <summary>
/// 머쓱이는 추운 날에도 아이스 아메리카노만 마십니다. 
/// 아이스 아메리카노는 한잔에 5,500원입니다. 
/// 머쓱이가 가지고 있는 돈 money가 매개변수로 주어질 때, 
/// 머쓱이가 최대로 마실 수 있는 아메리카노의 잔 수와 남는 돈을 
/// 순서대로 담은 배열을 return 하도록 solution 함수를 완성해보세요.
/// </summary>
public class 아이스_아메리카노
{
    public int[] solution(int money)
    {
        int[] answer = new int[2];
        int price = 5500;

        if(money < price)
        {
            answer[0] = 0;
            answer[1] = money;
        }
        else
        {
            answer[0] = (int)money / price;
            answer[1] = (int)money % price;
        }

        return answer;
    }

    public int[] solution2(int money) // programmers
    {
        return new int[] { money / 5500, money % 5500 };
    }
}

