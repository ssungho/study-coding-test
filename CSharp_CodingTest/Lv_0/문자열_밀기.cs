internal class 문자열_밀기
{
    public int solution(string A, string B)
    {
        int cnt = 0;
        while (cnt < A.Length)
        {
            string temp = "";
            for (int i = A.Length - cnt; i < A.Length; i++)
                temp += A[i];

            for (int i = 0; i < A.Length - cnt; i++)
                temp += A[i];

            if (temp == B)
                return cnt;
            else
                cnt++;
        }
        return -1;
    }
}

