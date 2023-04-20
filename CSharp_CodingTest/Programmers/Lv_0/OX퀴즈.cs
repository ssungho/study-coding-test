using System;
/// <summary>
/// 덧셈, 뺄셈 수식들이 'X [연산자] Y = Z' 형태로 들어있는 문자열 배열 quiz가 매개변수로 주어집니다. 
/// 수식이 옳다면 "O"를 틀리다면 "X"를 순서대로 담은 배열을 return하도록 solution 함수를 완성해주세요.
/// </summary>

internal class OX퀴즈
{
    public string[] solution(string[] quiz)
    {
        string[] answer = new string[quiz.Length];
        for (int i = 0; i < quiz.Length; i++)
        {
            List<int> callist = new List<int>();
            bool plus = false;
            string[] cals = quiz[i].Split(' ');
            for(int j = 0; j < cals.Length; j++)
            {
                if (cals[j] != "-" && cals[j] != "+" && cals[j] != "=")
                    callist.Add(int.Parse(cals[j]));
                if (cals[j] == "+")
                    plus = true;
                if (cals[j] == "-")
                    plus = false;
            }
            if (plus == true)
            { 
                if (callist[0] + callist[1] == callist[2])
                    answer[i] = "O";
                else 
                    answer[i] = "X";
            }
            else
            {
                if (callist[0] - callist[1] == callist[2])
                    answer[i] = "O";
                else
                    answer[i] = "X";
            }
        }
        return answer;
    }
}

