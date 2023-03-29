class Test
{
    static void Main(string[] args)
    {
        직사각형_넓이_구하기 test = new();

        while (true)
        {
            // string[] ans = new string[2] { "3 - 4 = -3", "5 + 6 = 11" };
             int[,] arr = { { -1, -1 }, { 1, 1 }, { 1, -1 },{ -1, 1 } };
            // string a = Console.ReadLine();
            // string b = Console.ReadLine();
            // int a = Convert.ToInt32(Console.ReadLine());
            // int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(arr));
            // int[] answer = test.solution(a);
            //foreach ( var c in answer)
            //{
            //    Console.WriteLine(c);
            //}
        }
    }
}
