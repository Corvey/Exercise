public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    public int maxSubArray(int[] nums) {
        // write your code
    	int ans = nums[0], cur, n = nums.length, positiveIndex;
    	for (positiveIndex = 0; positiveIndex < n && nums[positiveIndex] <= 0; ++positiveIndex) {
    		if (nums[positiveIndex] > ans)
    			ans = nums[positiveIndex];
    	}
    	if (positiveIndex != n) {
    		cur = 0;
    		for (int i = positiveIndex; i < n; ++i) {
    			cur += nums[i];
    			if (cur < 0) {
    				cur = 0;
    			} else if (cur > ans) {
    				ans = cur;
    			}
    		}
    	}
    	return ans;
    }
}