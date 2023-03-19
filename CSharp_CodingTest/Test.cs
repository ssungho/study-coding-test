class Test
{
    static void Main(string[] args)
    {
        팩토리얼 test = new();

        while (true)
        {
            // int[] arr = { 13, 2, 3 };
            // string a = Console.ReadLine();
            int a = Convert.ToInt32(Console.ReadLine());
            // int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(a));
        }
    }
}
