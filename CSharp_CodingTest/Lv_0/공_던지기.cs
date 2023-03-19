using System;
/// <summary>
/// 머쓱이는 친구들과 동그랗게 서서 공 던지기 게임을 하고 있습니다. 
/// 공은 1번부터 던지며 오른쪽으로 한 명을 건너뛰고 그다음 사람에게만 던질 수 있습니다.
/// 친구들의 번호가 들어있는 정수 배열 numbers와 정수 K가 주어질 때, 
/// k번째로 공을 던지는 사람의 번호는 무엇인지 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class 공_던지기
{
    public int solution(int[] numbers, int k)
    {
        int answer = 0;
        int next = 0;
         // k 번째로 공을 던지는 사람을 구하는 것이기 때문에 k -1까지 반복
        for (int i = 0; i < k - 1; i++)
        {
            next = next + 2;
            // next = 6 numbers.length = 6경우를 고려해보면..
            if(next > numbers.Length - 1)
            {
                next = next - (numbers.Length);
            }
            answer = numbers[next];
        }


        return answer;
    }
}

