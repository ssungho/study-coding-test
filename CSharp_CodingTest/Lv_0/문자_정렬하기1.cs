/// <summary>
/// 문자열 my_string이 매개변수로 주어질 때, 
/// my_string 안에 있는 숫자만 골라 오름차순 정렬한 리스트를 return 하도록 solution 함수를 작성해보세요.
/// </summary>
internal class 문자_정렬하기1
{
    public int[] solution(string my_string)
    {
        // 숫자를 걸러서 담을 리스트를 생성한다.
        List<int> list = new List<int>();

        // 받는 문자열의 길이만큼 반복한다.
        for (int i = 0; i < my_string.Length; i++)
        {
            // 문자열의[i]번째 값이 0~9 중 하나일 경우 그 숫자를 리스트에 담는다. 
            for (int j = 0; j < 10; j++)
            {
                if (my_string[i].ToString() == j.ToString())
                    list.Add(j);
            }
        }
        // 리스트를 오름차순으로 정렬한다.
        list.Sort();
        // 리스트를 배열로 바꾼다.
        int[] answer = list.ToArray();
        return answer;
    }
}

