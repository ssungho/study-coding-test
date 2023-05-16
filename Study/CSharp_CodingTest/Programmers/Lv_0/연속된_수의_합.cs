internal class 연속된_수의_합
{
    public int[] solution(int num, int total)
    {
        int[] answer = new int[num];  
        int center = total / num;
        int cnt = 1;
        for (int i = 0; i < num; i++)
        { 
            if (i < num / 2)
                answer[num / 2 -1 - i] = center - i -1;
            if (i == num / 2)
                answer[num / 2] = center;
            if (i > num / 2)
            {
                answer[i] = center + cnt;
                cnt++;
            }
        }
        int temp = 0;
        for (int i = 0; i < num; i++)
            temp += answer[i];

        if (temp != total)
            for (int i = 0; i < num; i++)
                answer[i] += 1;
        return answer;
    }
}

