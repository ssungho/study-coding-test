using System.Linq;

namespace 모의고사
{
    public class Solution
    {
        public int[] solution(int[] answers)
        {
            int[] scores = new int[3];

            int[] s1 = new int[] { 1, 2, 3, 4, 5 };
            int[] s2 = new int[] { 2, 1, 2, 3, 2, 4, 2, 5 };
            int[] s3 = new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

            for (int i = 0; i < answers.Length; i++)
            {
                if (answers[i] == s1[i % s1.Length])
                    scores[0] += 1;
                if (answers[i] == s2[i % s2.Length])
                    scores[1] += 1;
                if (answers[i] == s3[i % s3.Length])
                    scores[2] += 1;
            }

            List<int> answer = new List<int>();
            if ((scores[0] == scores.Max()))
                answer.Add(1);
            if ((scores[1] == scores.Max()))
                answer.Add(2);
            if ((scores[2] == scores.Max()))
                answer.Add(3);
            return answer.ToArray();
        }
    }
}
