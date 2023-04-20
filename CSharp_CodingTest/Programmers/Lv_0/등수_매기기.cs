using System;

internal class 등수_매기기
{
    public int[] solution(int[,] score)
    {
        // score의 원소의 갯수만큼 새로운 배열을 초기화.
        int[] answer = new int[score.GetLength(0)];
        float[] rank = new float[score.GetLength(0)];
        // score의 원소의 갯수만큼 반복한다.
        for (int i = 0; i < score.GetLength(0); i++)
            rank[i] = (float)(score[i, 0] + score[i, 1]) / 2;

        for (int i = 0; i < score.GetLength(0); i++)
        {
            int cnt = 0;
            for (int j = 0; j < score.GetLength(0); j++)
                // 만약 자신과 다른 사람의 점수를 비교했을때 다른 사람이 더 높다면 
                if (rank[i] < rank[j])
                    // 내 등수는 + 1.
                    cnt++;
            // 내 등수는 +1. (0부터 시작했으니까)
            answer[i] = cnt + 1;
        }
        return answer;
    }
}

