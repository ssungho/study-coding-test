class Test
{
    static void Main(string[] args)
    {
        피자_나눠먹기1.Solution s = new 피자_나눠먹기1.Solution();
        while (true)
        {
            int answer = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(s.solution(answer));
        }
    }
}
