namespace 프로세스
{
    public class Solution
    {
        public int solution(int[] priorities, int location)
        {
            int answer = 0;
            Queue<(int, bool)> q = new Queue<(int, bool)>();

            for (int i = 0; i < priorities.Length; i++)
                if (i == location)
                    q.Enqueue((priorities[i], true));

                else
                    q.Enqueue((priorities[i], false));

            while (q.Count > 0)
            {
                if (q.Peek().Item2 == true && q.Peek().Item1 == q.Max().Item1)
                {
                    answer++;
                    return answer;
                }
                else if (q.Peek().Item1 == q.Max().Item1)
                {
                    q.Dequeue();
                    answer++;
                }
                else if (q.Peek().Item1 != q.Max().Item1)
                    q.Enqueue(q.Dequeue());
                
            }
            return answer;
        }
    }
}
