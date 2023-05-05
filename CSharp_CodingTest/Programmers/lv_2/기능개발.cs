using System;
using System.Collections;

namespace 기능개발
{
    public class Solution
    {
        public int[] solution(int[] progresses, int[] speeds)
        {
            List<int> sol = new List<int>();
            Queue<int> q = new Queue<int>();
            int count = 0;
            int day = 1;

            for (int i = 0; i < progresses.Length; i++)
                q.Enqueue(progresses[i]);

            while (q.Count > 0)
            {
                if(q.Peek() + speeds[count] * day >= 100)
                {
                    int total = 0;
                    while (q.Count > 0 && q.Peek() + speeds[count] * day >= 100)
                    {
                        q.Dequeue();
                        count++;
                        total++;
                    }
                    sol.Add(total);
                }
                day++;
            }
            return sol.ToArray();
        }
    }
}
