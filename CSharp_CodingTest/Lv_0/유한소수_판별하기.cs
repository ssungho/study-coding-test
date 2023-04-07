using System;
/// <summary>
/// 소수점 아래 숫자가 계속되지 않고 유한개인 소수를 유한소수라고 합니다.
/// 분수를 소수로 고칠 때 유한소수로 나타낼 수 있는 분수인지 판별하려고 합니다. 
/// 유한소수가 되기 위한 분수의 조건은 다음과 같습니다.
///     기약분수로 나타내었을 때, 분모의 소인수가 2와 5만 존재해야 합니다.
/// 두 정수 a와 b가 매개변수로 주어질 때, a/b가 유한소수이면 1을, 무한소수라면 2를 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 유한소수_판별하기
{
    public int solution(int a, int b)
    {
        int cnt = 2;
        // 최대 공약수까지 반복
        while (cnt <= a || cnt <= b)
        {
            if (a % cnt == 0 && b % cnt == 0)
            {
                a /= cnt;
                b /= cnt;
            }
            if (b == 1) 
                return 1;
            cnt++;
        }
        // 분모가 2혹은 5로 나눠진다면 반복
        while (b % 2 == 0 || b % 5 == 0)
        {
            if (b % 2 == 0)
                b /= 2;
            if (b % 5 == 0)
                b /= 5;
        }
        if (b != 1)
            return 2;
        else
            return 1;
    }
}

