public class Solution {
    /**
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    public int minSubArray(ArrayList<Integer> nums) {
        // write your code
        int ans = nums.get(0), cur, index, n = nums.size(), x;
    	for (index = 0; index < n; ++index) {
    		x = nums.get(index);
    		if (x < 0) {
    			break;
    		} else if (x < ans) {
    			ans = x;
    		}
    	}
    	if (index != n) {
    		cur = 0;
    		for (int i = index; i < n; ++i) {
    			cur += nums.get(i);
    			if (cur > 0) {
    				cur = 0;
    			} else if (cur < ans) {
    				ans = cur;
    			}
    		}
    	}
    	return ans;
    }
}
