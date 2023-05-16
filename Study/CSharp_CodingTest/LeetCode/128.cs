public class Longest_Consecutive_Sequence
{
    public int LongestConsecutive(int[] nums)
    {
        Dictionary<int, bool> numsDict = new Dictionary<int, bool>();
        int longest = 0;
        foreach (int num in nums)
            numsDict[num] = true;

        for (int i = 0; i < nums.Length; i++) // n번 반복
        {
            if (!numsDict.ContainsKey(nums[i] - 1)) // O(1)으로 가능
            {
                int cnt = 1;
                int target = nums[i] + 1;
                while (numsDict.ContainsKey(target)) // 총 n번
                {
                    cnt += 1;
                    target += 1;
                }
                longest = Math.Max(longest, cnt);
            }
        }
        return longest;
    }
}
