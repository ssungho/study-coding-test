class Test
{
    static void Main(string[] args)
    {
        문자열_밀기 test = new();

        while (true)
        {
            // string[] ans = new string[2] { "3 - 4 = -3", "5 + 6 = 11" };
            // int[,] arr = { { -1, -1 }, { 1, 1 }, { 1, -1 },{ -1, 1 } };
            string a = Console.ReadLine();
            string b = Console.ReadLine();
            // int a = Convert.ToInt32(Console.ReadLine());
            // int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(a, b));
            // int[] answer = test.solution(a);
            //foreach ( var c in answer)
            //{
            //    Console.WriteLine(c);
            //}
        }
    }
}
