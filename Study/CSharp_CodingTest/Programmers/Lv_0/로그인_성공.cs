using System;
internal class 로그인_성공
{
    public string solution(string[] id_pw, string[,] db)
    {
        for (int i = 0; i < db.GetLength(0); i++)
        {
            if (db[i, 0] == id_pw[0])
            {
                if (db[i,1] == id_pw[1])
                    return "login";
                return "wrong pw";
            }
        }
        return "fail";
    }
}

