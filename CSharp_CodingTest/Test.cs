class Test
{
    static void Main(string[] args)
    {
        문자_정렬하기1 test = new();

        while (true)
        {
            // int[] arr = { 13, 2, 3 };
            string a = Console.ReadLine();
            // int a = Convert.ToInt32(Console.ReadLine());
            // int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(a));
        }
    }
}
