class Test
{
    static void Main(string[] args)
    {
        구슬을_나누는_경우의_수 test = new();

        while (true)
        {
            // int[] arr = { 13, 2, 3 };
            // string a = Console.ReadLine();
            int a = Convert.ToInt32(Console.ReadLine());
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(a, b));
        }
    }
}
