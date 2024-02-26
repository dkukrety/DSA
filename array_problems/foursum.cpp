// Better way is to use hashmap

// TC = O(n^3)
// SC = O(n)
// Consistent with TwoSum and ThreeSum
public
class Solution
{
public
    IList<IList<int>> FourSum(int[] nums, int target)
    {
        IList<IList<int>> result = new List<IList<int>>();
        HashSet<(int, int, int, int)> lookup = new ();
        for (int a = 0; a < nums.Length; a++)
        {
            var threeSumIndices = ThreeSum(nums, a + 1, (target - nums[a]));
            if (threeSumIndices.Count > 0)
            {
                foreach (var(b, c, d) in threeSumIndices)
                {
                    int[] arr = new int[4]{nums[a], nums[b], nums[c], nums[d]};
                    Array.Sort(arr);
                    if (!lookup.Contains((arr[0], arr[1], arr[2], arr[3])))
                    {
                        lookup.Add((arr[0], arr[1], arr[2], arr[3]));
                        result.Add(new List<int>{nums[a], nums[b], nums[c], nums[d]});
                    }
                }
            }
        }
        return result;
    }

public
    List<(int, int, int)> ThreeSum(int[] nums, int startIndex, long target)
    {
        List<(int, int, int)> result = new ();
        for (int b = startIndex; b < nums.Length; b++)
        {
            var twoSumIndices = TwoSum(nums, b + 1, (target - (long)nums[b]));
            if (twoSumIndices.Count > 0)
            {
                foreach (var(c, d) in twoSumIndices)
                    result.Add((b, c, d));
            }
        }
        return result;
    }

public
    List<(int, int)> TwoSum(int[] nums, int startIndex, long target)
    {
        Dictionary<long, int> lookup = new ();
        List<(int, int)> result = new ();
        for (int i = startIndex; i < nums.Length; i++)
        {
            if (lookup.ContainsKey(target - (long)nums[i]))
                result.Add((i, lookup[target - nums[i]]));
            else if (!lookup.ContainsKey(nums[i]))
                lookup.Add(nums[i], i);
        }
        return result;
    }
}