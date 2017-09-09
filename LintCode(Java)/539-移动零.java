public class Solution {
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    public void moveZeroes(int[] nums) {
        // Write your code here
        int n = nums.length, pos;
    	for (pos=0; pos<n && nums[pos] != 0; ++pos);
    	for (int i=pos+1; i<n; ++i) {
    		if (nums[i] != 0) {
    			nums[pos++] = nums[i];
    		}
    	}
    	for (int i=pos; i<n; nums[i++]=0);
    }
}