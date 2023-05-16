using System;
using System.Runtime.ExceptionServices;
/// <summary>
/// "*"의 높이와 너비를 1이라고 했을 때, "*"을 이용해 직각 이등변 삼각형을 그리려고합니다. 
/// 정수 n 이 주어지면 높이와 너비가 n 인 직각 이등변 삼각형을 출력하도록 코드를 작성해보세요.
/// </summary>
class 직각삼각형_출력하기
{
    public class Example
    {
        public static void Main()
        {
            String[] s;
            Console.Clear();
            s = Console.ReadLine().Split(' ');
            int n = Int32.Parse(s[0]);
            string a = "*";

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <=i; j++)
                {
                    Console.Write(a);
                }
                Console.WriteLine();
            }
        }
    }
}
#region gpt
/*
using System;

class MainClass {
  public static void Main (string[] args) {
    int n = int.Parse(Console.ReadLine());  // 사용자로부터 정수 n 입력 받음

    // 삼각형을 출력하는 부분
    for (int i = 0; i < n; i++) {  // 높이가 n인 삼각형을 출력하기 위해 n번 반복
      for (int j = 0; j <= i; j++) {  // 삼각형의 각 줄마다 출력할 "*" 개수 결정
        Console.Write("*");  // "*" 출력
      }
      Console.WriteLine();  // 한 줄의 출력이 끝나면 줄바꿈
    }
  }
}

 */
#endregion
