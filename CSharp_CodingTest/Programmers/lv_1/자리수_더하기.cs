internal class 자리수_더하기
{
    public int solution(int n)
    {
        int answer = 0;
        while (n >= 1)
        {
            answer += (n % 10);
            n /= 10;
        }
        return answer;
    }
}

