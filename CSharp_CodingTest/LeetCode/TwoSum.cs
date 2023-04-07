public class Solution
{
    // 동일 인덱스를 안쓰게 하려면 어떻게 해야 할까? 
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            if (dict.ContainsKey(target - nums[i]) && dict[target - nums[i]] != i)
                return new int[] { dict[target - nums[i]], i };
            dict[nums[i]] = i;
        }
        return null;
    }
}