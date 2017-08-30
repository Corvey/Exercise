public class Solution {
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return an integer
     */
    public int findPosition(int[] nums, int target) {
        // Write your code here
        int n = nums.length, l = 0, r = n-1, cur;
    	while (l <= r) {
    		cur = l + r >> 1;
    		if (target == nums[cur]) {
    			return cur;
    		} else if (target < nums[cur]) {
    			r = cur - 1;
    		} else {
    			l = cur + 1;
    		}
    	}
    	return -1;
    }
}