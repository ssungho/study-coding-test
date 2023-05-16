using System.Runtime.Intrinsics.X86;

internal class 옹알이
{
    public int solution(string[] babbling)
    {
        int answer = 0;
        string[] can = new string[4] { "aya", "ye", "woo", "ma" };

        for (int i = 0; i < babbling.Length; i++)
        {
            int cnt = 0;
            while(cnt < 4)
            {
                if (babbling[i].Contains(can[cnt]))
                    babbling[i] = babbling[i].Replace(can[cnt], " ");
                cnt++;
            }
            if (babbling[i].Replace(" ","") == "")
                answer++;
        }
        return answer;
    }
}

