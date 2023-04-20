using System;
/// <summary>
/// 문자열 before와 after가 매개변수로 주어질 때,
/// before의 순서를 바꾸어 after를 만들 수 있으면 1을, 
/// 만들 수 없으면 0을 return 하도록 solution 함수를 완성해보세요.
/// </summary>
internal class A로_B만들기
{
    public int solution(string before, string after)
    {
        // 문자 배열로 전환
        char[] bChars = before.ToCharArray();
        char[] aChars = after.ToCharArray();
        // 정렬
        Array.Sort(bChars);
        Array.Sort(aChars);
        // 문자열로 바꾼 뒤 비교
        if (new string(aChars) == new string(bChars))
            return 1;
        else
            return 0;
    }
}

