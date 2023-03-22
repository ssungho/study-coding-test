class Test
{
    static void Main(string[] args)
    {
        제곱수_판별하기 test = new();

        while (true)
        {
            // int[] arr = { 3, 10, 28 };
            // string a = Console.ReadLine();
            // string b = Console.ReadLine();
            int a = Convert.ToInt32(Console.ReadLine());
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
