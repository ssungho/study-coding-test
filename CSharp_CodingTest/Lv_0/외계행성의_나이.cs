using System;
/// <summary>
/// 우주여행을 하던 머쓱이는 엔진 고장으로 PROGRAMMERS-962 행성에 불시착하게 됐습니다. 
/// 입국심사에서 나이를 말해야 하는데, PROGRAMMERS-962 행성에서는 나이를 알파벳으로 말하고 있습니다. 
/// a는 0, b는 1, c는 2, ..., j는 9입니다. 예를 들어 23살은 cd, 51살은 fb로 표현합니다. 
/// 나이 age가 매개변수로 주어질 때 PROGRAMMER-962식 나이를 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 외계행성의_나이
{
    public string solution(int age)
    {
        string answer = "";
        string _age = "abcdefghij";
        if (age < 10)
        {
            answer += _age.Substring(age, 1);
        }
        if (age >= 10 && age < 100)
        {
            answer += _age.Substring((int)age / 10, 1);
            answer += _age.Substring(age % 10, 1);
        }
        if (age >= 100 && age < 1000)
        {
            answer += _age.Substring((int)age/100, 1);
            answer += _age.Substring((int)(age - ((int)age/100) * 100) /10 , 1);
            answer += _age.Substring(age % 10, 1);
        }
        if (age == 1000)
        {
            answer += _age.Substring(age / 1000, 1);
            answer += _age.Substring(0,1);
            answer += _age.Substring(0, 1);
            answer += _age.Substring(0, 1);
        }
        return answer;
    }

    public string ConvertToProgrammerAge(int age) // GPT ex1
    {
        string alphabet = "abcdefghij";
        int baseNumber = 10;
        string result = "";

        do
        {
            int digit = age % baseNumber;
            result = alphabet[digit] + result;
            age /= baseNumber;
        } while (age > 0);

        return result;
    }

    public static string ConvertToProgrammerAge2(int age) // GPT ex2
    {
        const string alphabet = "abcdefghij";
        string result = "";

        if (age == 0) return "a"; // Special case for age zero

        while (age > 0)
        {
            int remainder = age % 10;
            result = alphabet[remainder] + result;
            age /= 10;
        }

        return result;
    }
}

