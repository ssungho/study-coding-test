using System.Security.Cryptography.X509Certificates;

class Test
{
    static void Main(string[] args)
    {
        진료순서_구하기 test = new 진료순서_구하기();
        while (true)
        {
            int[] arr = { 13, 2, 3 };
            // string a = Console.ReadLine();
            // string b = Console.ReadLine();
            // int a = Convert.ToInt32(Console.ReadLine());
            // int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(test.solution(arr));
            break;
        }
    }
}
