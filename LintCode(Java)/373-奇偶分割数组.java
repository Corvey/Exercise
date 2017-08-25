public class Solution {
    /**
     * @param nums: an array of integers
     * @return: nothing
     */
    public void partitionArray(int[] nums) {
        // write your code here;
    	int oddIndex, evenIndex, n = nums.length, t;
    	for (evenIndex = 0; evenIndex < n && (nums[evenIndex] & 1) != 0; ++evenIndex);
    	if (evenIndex != n) {
    		for (oddIndex = evenIndex+1; oddIndex < n; ++oddIndex) {
    			if ((nums[oddIndex] & 1) == 1) {
    				t = nums[oddIndex];
    				nums[oddIndex] = nums[evenIndex];
    				nums[evenIndex] = t;
    				++evenIndex;
    			}
    		}
    	}
    }
}