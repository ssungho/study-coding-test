public class Daily_Temperatures
{
    public int[] DailyTemperatures(int[] temperatures)
    {
        // 정답으로 반환할 배열을 초기화한다.
        int[] answer = new int[temperatures.Length];
        // int로 구성된 튜플 스택을 생성한다.
        Stack<(int, int)> stack = new Stack<(int, int)>();
        // 주어진 배열만큼 반복 O(N)
        for (int i = 0; i < temperatures.Length; i++)
        {
            // 스택이 0이 아니고, 스택의 Top(Peek())의 온도값이 현재 온도보다 작다면, 
            while (stack.Count != 0 && stack.Peek().Item1 < temperatures[i])
            {
                // 저장 당시 i값을 prev_day에 임시 저장
                int prev_day = stack.Peek().Item2;
                // 스택에서 제거후
                stack.Pop();
                // 정답배열의 [prev_day]값은 현재(i) - 저장 당시(i값)
                answer[prev_day] = i - prev_day;
            }
            // 스택에 현재 온도와 현재 날(?)을 저장한다.    
            stack.Push((temperatures[i], i));
        }
        return answer;
    }
}

