class Test
{
    static void Main(string[] args)
    {
        컨트롤_제트 test = new();

        while (true)
        {
            // int[] arr = { 13, 2, 3 };
            string a = Console.ReadLine();
            // int a = Convert.ToInt32(Console.ReadLine());
            // int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(a));
            // int[] answer = test.solution(a);
            //foreach ( var c in answer)
            //{
            //    Console.WriteLine(c);
            //}
        }
    }
}
