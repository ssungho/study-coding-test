using System;
using System.Linq;

public class 최빈값_구하기
{
    public int solution(int[] array)
    {
        Array.Sort(array);
        int answer = 0;
        int max1 = array[array.Length - 1];
        int max2 = 0;
        int[] numbers = new int[max1 + 1];
        int count = 0;

        for (int i = 0; i < array.Length; i++)
        {
            numbers[array[i]]++;
        }

        for (int i = 0; i < numbers.Length; i++)
        {
            if (numbers[i] > max2)
            {
                max2 = numbers[i];
                answer = i;
            }
        }

        for (int i = 0; i < numbers.Length; i++)
        {
            if (numbers[i] == max2)
                count++;
        }

        if (count == 1)
            return answer;
        else
            return -1;
    }
}