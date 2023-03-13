class Test
{
    static void Main(string[] args)
    {
        양꼬치 test = new 양꼬치();
        while (true)
        {
            int a = Convert.ToInt32(Console.ReadLine());
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(a,b));
            
        }
    }
}
