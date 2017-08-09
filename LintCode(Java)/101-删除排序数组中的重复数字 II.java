public class Solution {
    /**
     * @param A: a array of integers
     * @return : return an integer
     */
    public int removeDuplicates(int[] nums) {
        // write your code here
    	int n = nums.length;
    	int pos, lastIndex = 0;
    	for (int i=0; i<n; i=pos) {
    		for (pos=i+1; pos<n && nums[pos] == nums[i]; ++pos);
    		if (pos - i == 1) {
    			nums[lastIndex++] = nums[i];
    		} else {
    			nums[lastIndex++] = nums[i];
    			nums[lastIndex++] = nums[i];
    		}
    	}
    	return lastIndex;
    }
}