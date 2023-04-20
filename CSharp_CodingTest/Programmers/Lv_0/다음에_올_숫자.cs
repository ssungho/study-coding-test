internal class 다음에_올_숫자
{
    public int solution(int[] common)
    {
        int answer = 0;
        int a;
        if(common[2] - common[1] == common[1] - common[0])
        {
            a = common[1] - common[0];
            return common[common.Length -1] + a;
        }
        else
        {
            a = common[1] / common[0];
            return common[common.Length -1] * a;
        }
    }
}

