class Test
{
    static void Main(string[] args)
    {
        A로_B만들기 test = new();

        while (true)
        {
            // string[] ans = new string[2] { "3 - 4 = -3", "5 + 6 = 11" };
            // int[] arr = { 3, 10, 28 };
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
