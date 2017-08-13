class Solution {
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    public int binarySearch(int[] nums, int target) {
        //write your code here
    	int n = nums.length, l = 0, r = n, mid;
    	while (l < r) {
    		mid = l + (r - l >> 1);
    		if (target <= nums[mid]) {
    			r = mid;
    		} else {
    			l = mid + 1;
    		}
    	}
    	return nums[l] == target ? l : -1;
    }
}