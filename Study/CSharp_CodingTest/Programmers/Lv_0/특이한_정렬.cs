/// <summary>
/// 정수 n을 기준으로 n과 가까운 수부터 정렬하려고 합니다. 이때 n으로부터의 거리가 같다면 더 큰 수를 앞에 오도록 배치합니다. 
/// 정수가 담긴 배열 numlist와 정수 n이 주어질 때 numlist의 원소를 n으로부터 가까운 순서대로 정렬한 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class 특이한_정렬
{
    public int[] solution(int[] numlist, int n)
    {
        int[] answer = new int[numlist.Length];
        for (int i = 0; i < numlist.Length - 1; i++)
        {
            for (int j = i + 1; j < numlist.Length; j++)
            {
                if (Math.Abs(numlist[i] - n) > Math.Abs(numlist[j] - n) || 
                    (Math.Abs(numlist[i] - n) == Math.Abs(numlist[j] - n) && numlist[i] < numlist[j]))
                {
                    int temp = numlist[i];
                    numlist[i] = numlist[j];
                    numlist[j] = temp;

                }       
            }
        }
        return answer = numlist;
    }
}
